N,X=map(int,input().split())
L=list(map(int,input().split()))
mem=0; ans=1
for i in L:
    mem+=i
    if mem<=X: ans+=1
print(ans)