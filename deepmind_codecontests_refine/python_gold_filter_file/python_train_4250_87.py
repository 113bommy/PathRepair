a,b,k=map(int,input().split())
count=0
s=[]
for i in range(1,101):
  if a%i==0 and b%i==0:
    s.append(i)
print(s[-k])