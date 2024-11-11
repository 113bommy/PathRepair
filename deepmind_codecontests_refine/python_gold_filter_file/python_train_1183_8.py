n, k = tuple(map(int,input().split()))
a = list(map(int,input().split()))
a.sort(reverse = True)

if k <= len(a):
    print(a[k-1], a[k-1])
else:
    print(-1)
