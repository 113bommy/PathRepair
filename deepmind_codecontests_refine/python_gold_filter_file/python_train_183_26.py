n=int(input())
a,b,c=[list(map(int,input().split())) for _ in range(3)] 
x=0
for i,_ in enumerate(a):
  if(i==len(a)-1):
    break
  elif(a[i]+1==a[i+1]):
    x+=c[a[i]-1]
print(sum(b)+x)