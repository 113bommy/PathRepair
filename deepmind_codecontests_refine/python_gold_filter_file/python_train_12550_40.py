a,b=map(int,input().split())
c=list(map(int,input().split()))
x=1
for i in range(a-1):
    if (c[i+1]-c[i])<=b:
        x+=1
    else:
        x=1
print(x)
    
