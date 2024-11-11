from collections import Counter
n,k=map(int,input().split())
s=input()
s+="%"
s=[i for i in s]
#print(s)
local=0
d={}
if n==1 and k==1:
    print(1)
elif n==1 and k>1:
    print(0)
else:
    for i in s:
        d[i]=0
    for i in range(len(s)-1):
        if s[i]==s[i+1]:
            local+=1
        else:
            d[s[i]]+=(local+1)//k
            local=0
    d[s[-1]]+=(local+1)//k
    del d['%']
    #print(d)
    print(max(d.values()))
            
