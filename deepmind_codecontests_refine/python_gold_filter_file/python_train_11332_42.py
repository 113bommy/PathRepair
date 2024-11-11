n,m = map(int,input().split())
A = [input() for _ in range(n)]
B = [input() for _ in range(m)]
ans = "No"
for i in range(n - m + 1):
  for j in range(n - m + 1):
    S = []
    for k in range(m):
      S.append(A[i + k][j:j + m])
      if S == B:
        ans = "Yes"
print(ans)