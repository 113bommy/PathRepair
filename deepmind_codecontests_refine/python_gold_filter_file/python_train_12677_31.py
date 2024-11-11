n,m,k = map(int,input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
A,B = [0],[0]
 
for i in range(n):
  A.append(a[i] + A[i])
for i in range(m):
  B.append(b[i] + B[i])
 
num,x = 0,m
 
for i in range(len(A)):
  if A[i] > k:
    break
  while A[i] + B[x] > k:
    x -= 1
  num = max(num, i + x)
  
print(num)
 