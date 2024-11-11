n=int(input())
x=0
l=[]
for i in range(n):
  a,b=map(int,input().split())
  l.append(a+b)
  x+=b
print(sum(sorted(l)[(n+1)%2::2])-x)