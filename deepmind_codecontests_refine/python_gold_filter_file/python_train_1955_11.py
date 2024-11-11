N = int(input())
M = 10
L = 2*M
A = [[0 for _ in range(L+1)] for _ in range(L+1)]

for _ in range(N):
  y = float(input())
  x = y
  x *= 10.**M
  x = int(x+0.1)
  k_2 = 0
  while x % 2 == 0 and k_2 < 2*M:
    x = x // 2
    k_2 += 1
  k_5 = 0 
  while x % 5 == 0 and k_5 < 2*M:
    x = x // 5
    k_5 += 1
  A[k_2][k_5] += 1

ans = 0
for k_2 in range(L+1):
  for k_5 in range(L+1):
    for l_2 in range(k_2, L+1):
      for l_5 in range(L+1):
        if k_2+l_2 >= 2*M and k_5+l_5 >= 2*M:
          if k_2 == l_2 and k_5 == l_5:
            ans += A[k_2][k_5]*(A[k_2][k_5]-1)//2
          elif l_2 > k_2 or (k_2 == l_2 and k_5 < l_5):
            ans += A[k_2][k_5]*A[l_2][l_5]          
#print(A)
print(ans)