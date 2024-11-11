N,K = map(int,input().split())
A = [int(i) for i in input().split()]

A = sorted(A)

B = []
C = []
D = []

for i in range(len(A)):
  if A[i] < 0:
    B.append(A[i])
  elif A[i] == 0:
    C.append(A[i])
  else:
    D.append(A[i])

b = len(B)
c = len(C)
d = len(D)

def f(n):#積がn以下になる組み合わせの個数
  if n < 0:
    i = 0
    j = 0
    k = 0
    while i < b and j < d:
      if B[i]*D[j] > n:
        j += 1
      else:
        i += 1
        k += d-j
    return k
  
  elif n == 0:
    return (c*(c-1))//2 + b*c + b*d + c*d
  
  else:
    i = 0
    j = b-1
    k = 0
    while i < b and j > -1:
      if B[i]*B[j] > n:
        i += 1
        k += j+1
      else:
        j -= 1
    
    k = b**2-k
    
    i = 0
    j = d-1
    while i < d and j > -1:
      if D[i]*D[j] <= n:
        i += 1
        k += j+1
      else:
        j -= 1
        
    l = 0   
    for i in range(b):
      if B[i]**2 <= n:
        l += 1
        
    for i in range(d):
      if D[i]**2 <= n:
        l += 1
        
    return (k-l)//2 + (c*(c-1))//2 + b*c + b*d + c*d
  
l = - 10**18
h = 10**18

while l+1 < h:
  m = (l+h)//2
  if f(m) >= K:
    h = m
  else:
    l = m

print(h)