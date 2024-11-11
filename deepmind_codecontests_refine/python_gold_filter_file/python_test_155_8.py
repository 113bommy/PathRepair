from sys import stdin
input=stdin.readline
rn=lambda:int(input())
rns=lambda:map(int,input().split())
rl=lambda:list(map(int,input().split()))
rs=lambda:input().strip()
YN=lambda x:print('YES') if x else print('NO')
ceil_div=lambda a,b:-(-a//b)
mod=10**9+7

for _ in range(rn()):
    n=rn()
    a=rl()
    s=rs()
    dis=[(a[i],i) for i in range(n) if s[i]=='0']
    lik=[(a[i],i) for i in range(n) if s[i]=='1']
    dis.sort()
    lik.sort()
    def swap(i,j):
        a[i],a[j]=a[j],a[i]
    i=0
    j=0
    while True:
        while i<len(dis) and dis[i][0]<=len(dis):
            i+=1
        while j<len(lik) and lik[j][0]>len(dis):
            j+=1
        if i==len(dis) or j==len(lik):
            break
        swap(dis[i][1],lik[j][1])
        i+=1
        j+=1
    print(*a)
