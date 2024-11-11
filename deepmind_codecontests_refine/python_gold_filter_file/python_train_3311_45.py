r,g,b,n = map(int,input().split())

cnt = 0
for i in range(n//r+1):
  for j in range(n//g+1):
    k = (n - i*r - j*g)/b
    if k>=0 and k.is_integer():
      cnt+=1
print(cnt)
