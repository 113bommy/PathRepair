n, k = map(int, input().split())
L = sorted(map(int, input().split()))
print(sum(L[-k:]))