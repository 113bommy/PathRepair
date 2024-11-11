n,x,k=list(map(int,input().split()))
a=list(map(int,input().split()))
from collections import Counter
ans=0
if k!=0:
    dn=Counter()
    un=Counter()
    for i in a:
        dn[i//x]+=1
        un[(i-0.1)//x]+=1
    for item,kol in un.items():
        ans+=kol*dn[item+k]
    print(ans)
else:
    dn = Counter()
    un = Counter()
    s=set()
    for i in a:
        if i%x!=0:
            un[i]+=1
            dn[i//x]+=1
    #print(dn,un,sep='\n')
    for item, kol in dn.items():
        ans += kol*(kol+1)//2
    for item, kol in un.items():
        ans += kol*(kol-1)//2
    print(ans)
