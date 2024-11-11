N, K = map(int, input().split())
t = N % K
print(min(K-t, t))