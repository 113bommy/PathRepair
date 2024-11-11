N=int(input())
A=list(map(int,input().split()))
cnt=0
for i in range(N-1):
  if i+1==A[i]:
    a=A[i]
    b=A[i+1]
    A[i]=b
    A[i+1]=a
    cnt+=1
if A[-1]==N:
  cnt+=1
print(cnt)