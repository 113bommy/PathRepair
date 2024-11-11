n,m=map(int,input().split())
for i in range(n,10**8):
  if m%i==0:
    print(m//i)
    exit()
print(1)


