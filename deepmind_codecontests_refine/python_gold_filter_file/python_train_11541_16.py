n,m,k=map(int,input().split())
for i in range(1,101):
  if (n*i)%m==k:
    print('YES')
    quit()
print('NO')