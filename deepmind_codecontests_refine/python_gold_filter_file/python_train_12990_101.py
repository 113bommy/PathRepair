a,b,n=map(int,input().split())
x=min(b-1,n)
print((a*x)//b-a*(x//b))