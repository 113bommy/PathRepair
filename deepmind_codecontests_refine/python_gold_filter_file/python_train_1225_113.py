n, k = map(int, input().split())
ps   = sorted(map(int, input().split()))

print(sum(ps[:k]))