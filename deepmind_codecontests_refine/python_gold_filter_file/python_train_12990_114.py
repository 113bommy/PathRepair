a,b,n=map(int,input().split())
f=lambda x:(a*x)//b-a*(x//b)
print(f(min(b-1,n)))