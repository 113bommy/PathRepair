n, k = map(int, input().split())
l = map(int, input().split())
l = sorted(l)
print(sum(l[-k:]))
