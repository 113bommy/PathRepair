N, K = map(int, input().split())
ans = N - K
ans = ans if K != 1 else 0
print(ans)