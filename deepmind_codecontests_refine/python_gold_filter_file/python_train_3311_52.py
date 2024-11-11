r,g,b,n=map(int,input().split())
ct=0
for i1 in range((n//r)+1):
  for i2 in range((n//g)+1):
    if (n-r*i1-g*i2)%b==0 and n-r*i1-g*i2>=0:
      ct+=1
print(ct)