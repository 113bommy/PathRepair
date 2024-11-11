n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
ans = 0
for s in range(n):
  for g in range(n):
    b = 0
    for via in range(n):
      if A[s][g] > A[s][via] + A[via][g]:
        print(-1)
        exit()
      if A[s][g] == A[s][via] + A[via][g]:
        b += 1
    if b == 2:
      ans += A[s][g]
print(ans//2)