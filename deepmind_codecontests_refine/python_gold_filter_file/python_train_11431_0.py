K, X = map(int, input().split())
ans = list(range(X-K+1,X+K,1))
print(*ans)