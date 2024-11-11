n, k = map(int, input().split())
r = range(1, n+1)

print(*r[:k+1][::-1], *r[k+1:])
