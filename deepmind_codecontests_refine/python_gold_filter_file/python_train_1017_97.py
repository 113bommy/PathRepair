n,k,s = map(int,input().split())
ans = [s if i<k else 10**9 if s!=10**9 else 10**9-1 for i in range(n)]
print(*ans)