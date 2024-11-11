n,a,b=map(int,input().split())
m=n//(a+b)
n-=m*(a+b)
print(m*a+min(a,n))