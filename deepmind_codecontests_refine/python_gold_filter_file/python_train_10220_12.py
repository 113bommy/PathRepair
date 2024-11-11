q = int(input())
for i in range(q):
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    if max(a) - k <= min(a) + k:
        print(min(a) + k)
    else:
        print(-1)
