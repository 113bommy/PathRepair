d={
    'A':0,
    'B':0,
    'C':0,
    'AB':0,
    'BC':0,
    'AC':0,
    'ABC':0
}
n=int(input())
for i in range(n):
    c,s=input().split()
    c=int(c)
    if s=='AB' or s=='BA':
        if d['AB']==0:
            d['AB']=c
        else:
            d['AB']=min(d['AB'],c)
    elif s=='BC' or s=='CB':
        if d['BC']==0:
            d['BC']=c
        else:
            d['BC']=min(d['BC'],c)
    elif s=='AC' or s=='CA':
        if d['AC']==0:
            d['AC']=c
        else:
            d['AC']=min(d['AC'],c)
    elif s=='A':
        if d['A']==0:
            d['A']=c
        else:
            d['A']=min(d['A'],c)
    elif s=='B':
        if d['B']==0:
            d['B']=c
        else:
            d['B']=min(d['B'],c)
    elif s=='C':
        if d['C']==0:
            d['C']=c
        else:
            d['C']=min(d['C'],c)
    elif sorted(s)==['A','B','C']:
        if d['ABC']==0:
            d['ABC']=c
        else:
            d['ABC']=min(d['ABC'],c)
ans=10**6
if d['ABC']:
    ans=min(ans,d['ABC'])
if d['AB']:
    if d['C']:
        ans=min(ans,d['AB']+d['C'])
    if d['BC']:
        ans=min(ans,d['AB']+d['BC'])
    if d['AC']:
        ans=min(ans,d['AB']+d['AC'])
if d['BC']:
    if d['A']:
        ans=min(ans,d['A']+d['BC'])
    if d['AB']:
        ans=min(ans,d['AB']+d['BC'])
    if d['AC']:
        ans=min(ans,d['BC']+d['AC'])
if d['AC']:
    if d['B']:
        ans=min(ans,d['AC']+d['B'])
    if d['AB']:
        ans=min(ans,d['AB']+d['AC'])
    if d['BC']:
        ans=min(ans,d['BC']+d['AC'])
if d['A'] and d['B'] and d['C']:
    ans=min(ans,d['A']+d['B']+d['C'])
if ans==10**6:
    print(-1)
else:
    print(ans)