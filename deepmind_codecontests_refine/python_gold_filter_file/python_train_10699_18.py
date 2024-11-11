def gauss_jordan(A):
  m=len(A)
  n=len(A[0])
  rank=0
  for col in range(n):
    pivot=-1
    for row in range(rank,m):
      if A[row][col]!=0:
        pivot=row
        break
    if pivot==-1:
      continue
    A[pivot],A[rank]=A[rank],A[pivot]
    for row in range(m):
      if row!=rank and A[row][col]!=0:
        for col2 in range(n):
          A[row][col2]^=A[rank][col2]      
    rank+=1
  if rank==len(A):
    return True
  else:
    return False

def make_vector(val):
  ret=[]
  for i in range(60,-1,-1):
    if val&(1<<i):
      ret.append(1)
    else:
      ret.append(0)
  return ret

t=int(input())
for _ in range(t):
  n=int(input())
  arr=list(map(int,input().split()))
  s=input()
  if s[-1]=='1':
    print(1)
    continue
  A=[make_vector(arr[-1])]
  for i in range(n-2,-1,-1):
    vector=make_vector(arr[i])
    if gauss_jordan(A+[vector]):
      if s[i]=='1':
        print(1)
        break
      if s[i]=='0':
        A.append(vector)
  else:
    print(0)