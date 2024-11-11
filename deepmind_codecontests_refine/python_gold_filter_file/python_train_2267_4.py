X,N = map(int,input().split())
P = list(map(int,input().split()))

res = 10**15
for i in range(-120,120):
  if i in P: continue
  if abs(i-X) < abs(res-X):
    res = i
print(res)