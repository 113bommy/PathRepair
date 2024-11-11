N, K = map(int, input().split())
As = list(map(int, input().split()))
for i in range(K):
  if min(As) == N:
    break
  dBs = [0]*(N+1)
  for i in range(N):
    A = As[i]
    dBs[max(0, i-A)] += 1
    dBs[min(N, i+A+1)] -= 1
  #print(dBs)
  Bs = [dBs[0]]
  for i in range(1, N):
    B = Bs[i-1]+dBs[i]
    Bs.append(B)
  As = Bs
print(" ".join(map(str, As)))
