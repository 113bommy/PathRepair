K,X = map(int, input().split())

l = list(range(X-K+1,X+K,1))

print(*l)