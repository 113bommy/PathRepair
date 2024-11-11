N = int(input())
A, B, C = input(), input(), input()
ans = 0
for i in range(N):
  ans += len(set([A[i], B[i], C[i]])) - 1
print(ans)