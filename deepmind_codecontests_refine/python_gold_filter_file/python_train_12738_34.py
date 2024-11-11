n = int(input().strip())
if n%2 != 0:
    print(-1)
else:
    ans = [i for i in range(n,0,-1)]
    print(*ans)
