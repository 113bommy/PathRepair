n,k=map(int,input().split())
x=[]
for i in range(2):
    a,b=map(int,input().split())
    x.append([a,b])
#x=sorted(x,reverse=True)
for i in range(k,-1,-1):
    n+=i
    if i == x[0][1]:
        if x[0][0]>n:
            n=0
        else:
            n-=x[0][0]
    elif i == x[1][1]:
        if x[1][0]>n:
            n=0
        else:
            n-=x[1][0]
if n<0:
    print(0)
else:
    print(n)

