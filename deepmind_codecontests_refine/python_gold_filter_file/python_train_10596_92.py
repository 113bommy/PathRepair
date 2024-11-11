n,k=map(int,input().split())
ct=0
while n>0:
  ct+=1
  n//=k
print(ct)