from math import ceil
N=int(input())
A=[int(i) for i in input().split()]
dp=1
for i in range(N):
  dp|=dp<<A[i]
S=sum(A)
hS=S//2
for i in range(hS+1)[::-1]:
  if dp&(1<<i):
    ans=i
    break
print(S-i)