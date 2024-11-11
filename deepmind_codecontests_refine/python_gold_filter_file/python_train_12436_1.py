def getNext(p):
    n=len(p)
    next=[-1]*n
    j=-1
    for i in range(1,n):
        while j>=0 and (p[j]-p[0])!=(p[i-1]-p[i-j-1]):
            j=next[j]
        j+=1
        next[i]=j
    return next
read=lambda:map(int,input().split())
n,w=read()
a=list(read())
b=list(read())
m=len(b)
next=getNext(b)
#print(next)
i,j=0,0
ans=0
while i<n:
    if j==-1 or a[i]-a[i-j]==b[j]-b[0]:
        i+=1
        j+=1
    else:
        j=next[j]
    if j==m:
        ans+=1
        j=next[m-1]
        i-=1
print(ans)