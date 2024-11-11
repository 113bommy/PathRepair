n=int(input())
a=list(map(int,input().split()))+[0]
c=a[0]
t=0
s=0
for i in range(n+1):
  if(c!=a[i]):
    c=a[i]
    s+=t//2
    t=1
  else:
    t+=1
print(s)
