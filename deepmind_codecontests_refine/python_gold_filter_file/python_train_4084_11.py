n = 0
a = [0]
i = 0
j = 0
x = 0
b = [0]
 
n = int(input())
b = list(map(int, input().split()))
a = a + b
 
cnt = [0] * 32
for i in range (1, n + 1):
    x = a[i]
    for j in range (0, 32):
        cnt[j] += x & 1
        x >>= 1
 
high = 0
for high in range (31, -1, -1):
    if cnt[high] == 1:
        break
 
if high == -1:
    for i in range (1, n + 1):
        print (a[i], end = ' ')
else:
    r = 0
    for r in range (1, n + 1):
        if (1 << high) & a[r] != 0:
            break
    
    print (a[r], end = ' ')
    for i in range (1, n + 1):
        if i == r:
            continue
        else:
            print (a[i], end = ' ')