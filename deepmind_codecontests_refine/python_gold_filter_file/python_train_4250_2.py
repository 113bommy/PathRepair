a,b,c=map(int,input().split())
l=[]
for i in range(1,max(a,b)+1):
  if a%i==0 and b%i==0:
    l.append(i)
print(l[-c])