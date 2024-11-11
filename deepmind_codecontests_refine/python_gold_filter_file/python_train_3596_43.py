c=0
n,x=map(int,input().split())
for i in range(n):
    a,b=input().split()
    if a=='+':
        x+=int(b)
    else:
        if int(b)<=x:
            x-=int(b)
        else:
            c+=1
print(x,c)