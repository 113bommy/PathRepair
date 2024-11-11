N = int(input())
W = list(map(int,input().split()))
L = []
for i in range(1,N):
  L.append(abs(sum(W[:i])-sum(W[i:])))
print(min(L))
