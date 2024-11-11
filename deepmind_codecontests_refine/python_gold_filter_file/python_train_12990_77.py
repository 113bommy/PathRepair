a,b,c=map(int,input().split())
x=min(b-1,c)
print((a*x)//b - a*(x//b))