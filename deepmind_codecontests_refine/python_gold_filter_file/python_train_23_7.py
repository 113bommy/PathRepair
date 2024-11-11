from sys import stdin
input=stdin.readline

def answer():
    if(n3+n1 < k or n3+n2 < k):return -1

    for i in range(1,n1+1):a[i]+=a[i-1]
    for i in range(1,n2+1):b[i]+=b[i-1]

    start=max(max(0,k-n1),max(0,k-n2))

    s=0
    for i in range(start):s+=common[i]

    ans=1e10
    for i in range(start,min(k,n3) + 1):
        ans=min(ans , s + a[k-i] + b[k-i])

        s+=common[i]

    return ans
     
n,k=map(int,input().split())

a,b,common=[0],[0],[]
for i in range(n):
    t,x,y=map(int,input().split())
    
    if(x and y):common.append(t)
    elif(x==1 and y==0):a.append(t)
    elif(x==0 and y==1):b.append(t)

common.sort()
a.sort()
b.sort()
common.append(0)

n1,n2,n3=len(a)-1,len(b)-1,len(common)-1

print(answer())
