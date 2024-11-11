N, K = map(int, input().split())
I = sorted(map(int, input().split()))
print(sum(I[-K:]))