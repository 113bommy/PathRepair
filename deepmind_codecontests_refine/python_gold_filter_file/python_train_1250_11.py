n = int(input())
a = list(map(int, input().split()))

s = 0
last = a[-1]

for i in range(n-1):
    if a[i] <= last:
        tmp = a[i]
        a[i] = a[s]
        a[s] = tmp
        s += 1
tmp = a[-1]
a[-1] = a[s]
a[s] = tmp

for i in range(0, s):
    print(a[i], end=' ')
print('[' + str(a[s]) + '] ', end='')
for i in range(s+1, n-1):
    print(a[i], end=' ')
print(a[n-1])
