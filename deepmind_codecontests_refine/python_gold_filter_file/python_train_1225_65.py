N, K = map(int, input().split())
p = tuple(map(int, input().split()))
print(sum(sorted(p)[:K]))