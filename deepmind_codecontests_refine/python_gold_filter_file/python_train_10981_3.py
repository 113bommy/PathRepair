from itertools import chain, combinations
def powerset(iterable):
    xs = list(iterable)
    # note we return an iterator rather than a list
    return list(chain.from_iterable(combinations(xs,n) for n in range(2,len(xs)+1)))
n,l,r,x=map(int,input().split())
sett=list(map(int,input().split()))
psett=powerset(sett)
count=0
for i in psett:
    k=sorted(i)
    j=sum(k)    
    if j>=l and j<=r and k[-1]-k[0]>=x:
        count+=1
print(count)


