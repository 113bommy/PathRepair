n=int(input())
G=[[0]*20 for i in range(45)]
A=[0,0,0,0]
for i in range(n):
  S=list(input())
  s=""
  f=0
  a=0
  for j in S:
    if j==".":
      f=1
    else:
      s=s+j
      if f==1:
        a=a+1
  A[0]=int(s)
  A[1]=a
  m=int(s)
  c=0
  while m%10==0:
    c=c+1
    m=m//10
  A[0]=m
  A[1]-=c
  m=A[0]
  c=0
  while m%2==0:
    c=c+1
    m=m//2
  A[2]=c
  c=0
  m=A[0]
  while m%5==0:
    c=c+1
    m=m//5
  A[3]=c
  G[A[2]-A[1]+9][A[3]-A[1]+9]+=1
B=[[0]*21 for i in range(46)]
for i in range(44,-1,-1):
  for j in range(19,-1,-1):
    B[i][j]=B[i+1][j]+B[i][j+1]-B[i+1][j+1]+G[i][j]
ans=0
for i in range(45):
  for j in range(20):
    ans=ans+G[i][j]*B[max(0,18-i)][max(0,18-j)]
    if i>=max(0,18-i) and j>=max(0,18-j):
      ans=ans-G[i][j]
print(ans//2)