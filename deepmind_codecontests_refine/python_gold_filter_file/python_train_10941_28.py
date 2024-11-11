n=int(input())
d={'A':10**9,'B':10**9,'C':10**9,'AB':10**9,'BC':10**9,'AC':10**9,'ABC':10**9}
#print(d['C'])
for i in range(n):
    c,s=input().split()
    s=list(s)
    c=int(c)
    s=''.join(sorted(s))
    d[s]=min(d[s],(c))
d['AB']=min(d['A']+d['B'],d['AB'])
d['BC']=min(d['B']+d['C'],d['BC'])
d['AC']=min(d['AC'],d['A']+d['C'])
d['ABC']=min(d['A']+d['B']+d['C'],d['AB']+d['C'],d['A']+d['BC'],d['B']+d['AC'],d['ABC'])
d['ABC']=min(d['AB']+d['BC'],d['AC']+d['BC'],d['AB']+d['AC'],d['ABC'])
if d['ABC']<10**9:
    print(d['ABC'])
else:
    print(-1)
    