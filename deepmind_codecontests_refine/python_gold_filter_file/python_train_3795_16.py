n = int(input())
j = n//2
k = 1
while j > 0:
  print('*'*j+'D'*k+'*'*j)
  j-=1
  k +=2
print('D'*n)
J = n-2
K = 1
while J > 0:
  print('*'*K+'D'*J+'*'*K)
  J-=2
  K+=1