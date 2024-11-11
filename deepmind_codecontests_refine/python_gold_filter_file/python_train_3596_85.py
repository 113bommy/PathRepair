n,x=list(map(int,input().split()))
r=0
for _ in range(n):
    c,p=list(map(str,input().split()))
    if(c=='+'):
        x+=int(p)
    else:
        if(x>=int(p)):
            x-=int(p)
        else:
            r+=1
print(x,r)
