N=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
n=0
for i in range(N):
  if A[i]>=B[i]:
    n+=B[i]
  else:
    l=min(B[i],A[i]+A[i+1])
    n+=l
    A[i+1]+=A[i]-l
print(n)