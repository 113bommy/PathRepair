n,a,b=map(int,input().split())
c=a+b
print(a*(n//c)+min(a,n%c))