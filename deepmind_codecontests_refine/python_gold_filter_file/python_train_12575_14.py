N = int(input())
S = input()

res = 0

for i in range(N - 1):
    for j in range(i + res, N):
        if S[i:j] not in S[j:]:
            break
    res = max(res, j - i - 1)

print(res)