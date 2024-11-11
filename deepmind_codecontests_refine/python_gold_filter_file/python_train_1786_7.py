def ck(p,q):
    return 1 if bpos[p]>fpos[q] else 0
n,k=map(int,input().split())
x=list(map(int,input().split()))
fpos=[-1 for i in range(100001)]
bpos=[k+5 for i in range(100001)]
for i in range(k):
    fpos[x[i]]=i
    bpos[x[k-1-i]]=k-1-i
ans=ck(n,n)
for i in range(1,n):
    ans+=ck(i,i)+ck(i,i+1)+ck(i+1,i)
print(ans)