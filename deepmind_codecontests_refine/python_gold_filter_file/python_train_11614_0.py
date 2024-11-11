'''codeforce task'''

import math

steps=0

def base_gen(b,l):
    n=[0]*l
    yield n[:]
    while not all(ne==b-1 for ne in n):
        p=l-1
        while n[p]==b-1:
            n[p]=0
            p-=1
        n[p]+=1
        yield n[:]

def deplete(pos,val,n,a,b,gs):        
    gs[pos-1]-=b*val
    gs[pos]-=a*val
    gs[pos+1]-=b*val
    #global steps
    #steps+=1
    
def fill_gaps(s,n,a,b,hs):
    gs=hs[:]
    for i in range(2,len(s)-1,2):
        deplete(i,s[i],n,a,b,gs)
    for i in range(1,len(s)-1,2):
        val=max([0]+[math.ceil(x) for x in [gs[i-1]/b,gs[i]/a]])
        s[i]=val
        deplete(i,s[i],n,a,b,gs)
    val=max(0,math.ceil(gs[-1]/b))
    s[-2]+=val
    deplete(len(s)-2,val,n,a,b,gs)
    return (s,gs)

def merged_base(bs,n):
    st=[0]*n
    for bi,be in enumerate(bs):
        st[2+bi*2]=be
    return st
    
#n,a,b=8,3,1
#hs=[2,5,5,6,2,5,5,2]
n,a,b=[int(x) for x in input().split()]
hs=[int(x) for x in input().split()]
hs=[hse+1 for hse in hs]
min_final_state=[]
min_score=float("inf")
for bs in base_gen(math.ceil((max(hs))/min(a,b))+1,(n-2)//2):
    st=merged_base(bs,n)        
    final_state,remained_health=fill_gaps(st,n,a,b,hs)
    assert all(rh<=0 for rh in remained_health)
    if sum(final_state)<min_score:
        min_score=sum(final_state)
        min_final_state=final_state
    
print(sum(min_final_state))
res=[]    
for i,v in enumerate(min_final_state):
    res+=[i+1]*v
print(*res)

#print('Total steps:',steps)