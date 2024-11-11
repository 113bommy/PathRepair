N, K = map(int, input().split())
l = list(sorted(map(int, input().split())))
print(sum(l[-K:]))
