n,k=map(int,input().split())
cost=list(map(int,input().split()))
s=input()
#exit(0)
a=[]
b=[]
c=[]
#print(n,k,cost)
kek1=0
kek2=0
kek3=0
for i in range(n):
    if (s[i]==chr(ord("W"))):
        kek1+=1
        a.append(cost[i])
    if (s[i]==chr(ord("O"))):
        kek2+=1
        b.append(cost[i])
    if (s[i]==chr(ord("R"))):
        kek3+=1
        c.append(cost[i])
a=sorted(a)
a=list(reversed(a))
b=sorted(b)
b=list(reversed(b))
c=sorted(c)
c=list(reversed(c))

pref_a=[]
pref_b=[]
pref_c=[]

if (kek1!=0):
    pref_a.append(a[0])
    for i in range(1,len(a)):
        pref_a.append(pref_a[len(pref_a)-1]+a[i])

if (kek2!=0):
    pref_b.append(b[0])
    for i in range(1,len(b)):
        pref_b.append(pref_b[len(pref_b)-1]+b[i])
        
if (kek3!=0):
    pref_c.append(c[0])
    for i in range(1,len(c)):
        pref_c.append(pref_c[len(pref_c)-1]+c[i])
        
inf=10**20
ans=-inf
for i in range(0,min(k-1,kek2)):
    cur=pref_b[i]
    left_k=k-(i+1)
    
    res_a=-inf
    res_c=-inf
    if (kek1):
        if (kek1>=left_k):
            res_a=pref_a[left_k-1]
    if (kek3):
        if (kek3>=left_k):
            res_c=pref_c[left_k-1]
            
    cur+=max(res_a,res_c)
    ans=max(ans,cur)
    
if (ans<-(10**18)):
    ans=-1
    
print(ans)