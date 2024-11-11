n,b,a=map(int,input().split())
l=list(map(int,input().split()))
maxa=a
c=0
ans=0
for i in range(n):
    if(a==0 and b==0):
        break
    elif(a==0):
        if(l[i]==1):
           a=min(a+1,maxa)
        b-=1
    elif(b==0):
        a=a-1
    elif(l[i]==1 and a<maxa):
        a=min(a+1,maxa)
        b-=1
    else:
        a=a-1
    ans+=1
print(ans)
