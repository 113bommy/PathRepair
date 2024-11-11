N, K, S = map(int, input().split())
arr = [1 if S > N else S + 1] * N
for i in range(K):
    arr[i] = S
print(*arr)