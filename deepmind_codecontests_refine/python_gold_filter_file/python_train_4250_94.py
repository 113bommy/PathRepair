A,B,K=map(int,input().split())

c=[]
for i in range(1,max(A,B)+1):
  if A % i == 0 and B % i == 0:
    c.append(i)
print(c[-K])