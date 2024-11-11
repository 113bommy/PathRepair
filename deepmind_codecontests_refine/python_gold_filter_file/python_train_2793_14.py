K = int(input())
A = [int(i) for i in input().split()]
A.reverse()

min_A=2
max_A=3
cnt=True
if A[0]!=2:
  print(-1)
  cnt=False
for i in range(1,K):
  a=(min_A+A[i]-1)//A[i]*A[i]
  b=max_A//A[i]*A[i]
  if a>b and cnt:
    print(-1)
    cnt=False
    break
  else:
    min_A=a
    max_A=b+A[i]-1

if cnt:
  print(min_A,max_A)
