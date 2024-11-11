a,b,c,x,y = map(int,input().split())
m=[]
for i in range(10**5+1):
  m.append(2*c*i + a*max(0,x-i) + b*max(0,y-i))
print(min(m))