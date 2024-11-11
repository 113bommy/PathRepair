n = int(input())
a = list(input().split())

if not n % 2:
    a.insert(n//2, 'a')
    n += 1

for i in range(n):
    if i % 2 and a[i] != 'a':
        print(a[i], end=' ')
    elif a[i] != 'a':
        print(a[n-1-i], end=' ')
