n,m=map(int,input().split())
ac=[0]*(n+1)
wa=[0]*(n+1)
for _ in range(m):
    i,j=input().split()
    i=int(i)
    if j=="AC":
        ac[i]=1
    elif ac[i]==0 and j=="WA":
        wa[i]+=1
print(sum(ac),sum(wa[i] for i in range(n+1) if ac[i]==1))  