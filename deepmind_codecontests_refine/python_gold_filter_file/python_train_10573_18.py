a,b,c,d=map(int,input().split())
x=min(a,c,d)
a=a-x
y=min(a,b)
print(256*x+32*y)