n,q=map(int,input().split())
a=[[0]*(n+1) for i in range(2)]
b=[]
n1=0
n2=0
n3=0
k=""
for i in range(q):
    typ,x=map(int,input().split())
    if typ==1:
        a[0][x]+=1
        b+=[x]
        n1+=1
        n2+=1
    elif typ==3:
        for i in range(n3,x):
            if i+1>a[1][b[i]]:
                a[0][b[i]]-=1
                n1-=1
        n3=max(n3,x)
    else:
        n1-=a[0][x]
        a[0][x]=0
        a[1][x]=n2
    # print(a,b,n1,n2,n3)
    k+=(str(n1)+'\n')
print(k)