N, K = map(int, input().split())
l = sorted(map(int, input().split()))

print(sum(l[-K:]))
