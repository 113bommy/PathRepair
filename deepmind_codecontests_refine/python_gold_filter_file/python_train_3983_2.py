M=998244353
n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
it=m-1
c=[0]*m
d=[[0,0] for i in range(m)]
ans=0
for i in range(n-1,-1,-1):
    if it <= 0 : break
    if a[i]<b[it] :
        if c[it]:
            d[it][0]=i+1
            it-=1
            d[it][1]=i
        else:
            print(ans)
            exit()
    if a[i]==b[it]: c[it]+=1
d[-1][-1]=n-1
for i in range(m):
    if min(a[d[i][0]:d[i][1]+1]) != b[i]:
        print(ans)
        exit()
#print(d,c)
ans,ANS=[1]*m,1
for i in range(m-1):
    for j in range(d[i][1]+1,d[i+1][1]):
        if a[j]==b[i+1]: c[i+1]-=1
        if c[i+1]: ans[i]+=1
        else: break
    ANS=((ANS%M)*(ans[i]%M))%M
print(ANS)    