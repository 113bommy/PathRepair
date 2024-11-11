N, K = map(int, input().split())
a = list(map(int, input().split()))

a.sort()
print(sum(a[:K]))