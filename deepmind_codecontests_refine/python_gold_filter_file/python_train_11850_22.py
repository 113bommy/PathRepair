N,M=map(int,input().split())
D=[]
for i in range(1,int(M**0.5+1)):
  if M%i==0:
    D.append(i)
    D.append(M//i)
D.sort()
for j in D:
  if j >=N:
    print(M//j)
    exit()