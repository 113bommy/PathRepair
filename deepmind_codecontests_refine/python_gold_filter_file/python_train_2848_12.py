n,k = map(int,input().split(' '))
a = list(input().split(' '))
k -= 1

same = 1
for i in range(k, n):
    if a[i] != a[k]:
        same = 0

if not same:
    print(-1)
else:
    c = -1
    for i in range(k):
        if a[i] != a[k]:
            c = i
    print(c + 1)

