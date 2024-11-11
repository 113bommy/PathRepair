N=int(input())
A=list(map(int,input().split()))
A.sort()
B=1
for i in range(0,len(A)):
  B=A[i]*B
  if(B>10**18):
    B=-1
    break
print(B)