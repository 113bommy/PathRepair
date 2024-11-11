N,K,S = map(int,input().split())

if S == 10**9:
    ans = [S]*K + [S-1]*(N-K)
else:
    ans = [S]*K + [S+1]*(N-K)
print(*ans)