t = int(input())
for _ in range(t):
    n = int(input())
    f = list(map(int, input().split()))
    if f[0]+f[1]<=f[-1]:
        print(1,2,n)
    else:
        print(-1 )