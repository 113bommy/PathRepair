n=int(input())
a,b=1,1

for i in range(n):
  x,y=map(int,input().split())
  s=-(-a//x)
  t=-(-b//y)
  a,b=max(s,t)*x,max(s,t)*y

print(a+b)