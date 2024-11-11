n = int(input())
l = list(map(int, input().split()))
k = 1
i = n-2
flag = 0
t = 0
for j in range(n-1):
    if l[j] != l[j+1]:
        flag += 1
        t = j
if n == 2:
    print(1)
elif flag == 1:
    print(t + 1)
else:
    while l[n-1] == l[i]:
        i -= 1
        k += 1
    print(n - k)
    
