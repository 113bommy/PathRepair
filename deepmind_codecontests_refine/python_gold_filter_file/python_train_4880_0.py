a=[]
n=int(input())
for i in range(10):
        a.append(-1)
while(n!=0):
    n-=1
    b=[]
    c=[]
    a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]=map(int,input().split())
    for i in range(10):
        b.append(-1)
        c.append(-1)
    j=1
    k=0
    lenb=0
    lenc=0
    b[0]=a[0]
    for i in range(1,10):
        if(a[i]>b[j-1]):
            b[j]=a[i]
            j+=1
        else:
            if(k==0):
                c[0]=a[i]
                k+=1
            elif(a[i]>c[k-1]):
                c[k]=a[i]
                k+=1
    for i in range(10):
        if(b[i]!=-1):
            lenb+=1
        if(c[i]!=-1):
            lenc+=1
    if(len(a)==(lenb+lenc)):
        print("YES")
    else:
        print("NO")