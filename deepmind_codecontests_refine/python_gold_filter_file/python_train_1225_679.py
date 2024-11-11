n, k = map(int, input().split())
*P, = map(int, input().split())
P.sort()
print(sum(P[:k]))
