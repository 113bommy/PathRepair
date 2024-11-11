x,y=map(int,input().split())
n=y//x
ct=0
while n>0:
  n//=2
  ct+=1
print(ct)