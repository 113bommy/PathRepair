import math

N = int(input())
A = list(map(int, input().split()))
m = max(A)
c = [0] * (m+1)
for i in A:
  c[i] += 1

pairwise = True
for i in range(2,m+1,1):
  cnt = 0
  for j in range(i,m+1,i):
    cnt += c[j]
  if cnt > 1:
    pairwise = False
if pairwise:
  print("pairwise coprime")
  exit()

g = 0
for i in range(N):
  g = math.gcd(g,A[i])
if g == 1:
  print("setwise coprime")
  exit()
print("not coprime")