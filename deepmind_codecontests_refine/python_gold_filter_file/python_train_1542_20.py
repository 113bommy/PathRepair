N = int(input())
A = [int(a) for a in input().split()]

ANS = [0] * N
for i in range(N)[::-1]:
    ans = A[i]
    for j in range(i+1, N+1, i+1):
        ans ^= ANS[j-1]
    ANS[i] = ans

print(sum(ANS))
print(*[i+1 for i in range(N) if ANS[i]])