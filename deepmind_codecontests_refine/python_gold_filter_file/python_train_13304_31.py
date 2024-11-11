l,r=map(int,input().split())
m=2018*2019
for i in range(l,r+1):
  for j in range(i+1,r+1):
    m=min(m,(i*j)%2019)
    if m==0:
      print(m)
      exit()
print(m)