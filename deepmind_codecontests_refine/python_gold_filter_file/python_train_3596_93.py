n,x=input().split()
n,x=int(n),int(x)
c=0
while n!=0:
    a,b=input().split()
    b=int(b)
    if a=="+":
        x=x+b
    if a=="-" and b<=x:
        x=x-b
    elif a=="-" and b>x:
        
        c+=1
    n-=1
print(x,c)
