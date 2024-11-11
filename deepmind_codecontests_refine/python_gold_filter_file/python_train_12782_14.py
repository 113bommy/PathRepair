import collections as cl
N = int(input())
A = list(map(int,input().split()))
cn = cl.Counter(A)
sumC = sum([n*(n-1)//2 for n in cn.values()])
for k in range(N):
  print(sumC - cn[A[k]] +1)