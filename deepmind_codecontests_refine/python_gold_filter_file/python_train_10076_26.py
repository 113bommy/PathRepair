N = int(input())
P = list(map(int, input().split()))
min = P[0]
cnt = 1
for p in P:
  if p < min:
    min = p
    cnt += 1
print(cnt)