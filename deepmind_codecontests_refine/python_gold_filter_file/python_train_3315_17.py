N, K = map(int, input().split())
print("Possible" if N*K*(N+K)%3==0 else "Impossible")