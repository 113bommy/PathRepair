n,k=map(int,input().split())
a=0
while n>0:
    n=n//k
    a=a+1
print(a)