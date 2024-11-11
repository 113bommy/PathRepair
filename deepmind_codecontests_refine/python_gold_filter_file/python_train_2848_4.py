n, k = map(int, input().split())
a = list(map(int, input().split()))
possible = True
if len(set(a[k-1::])) != 1:
    possible = False

if possible:
    c = 0
    for i in range(k-1):
        if a[i] != a[k-1]:
            c = i+1
    print(c)
else:
    print(-1)
