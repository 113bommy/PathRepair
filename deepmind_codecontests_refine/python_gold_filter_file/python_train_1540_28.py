N, M = map(int, input().split())
A = list(map(int, input().split()))
ans = max(-1, N-sum(A))
print(ans)