'''
the max element would have 0 0 i both l,r
'''
from  collections  import defaultdict
def f(l,r):
    cnts=defaultdict(list)
    lmax=[0]*len(l)
    rmax=[0]*len(l)
    for i in range(len(l)):
        cnts[l[i]+r[i]].append(i)
    mx=len(l)
    ans=[0]*(len(l))
    for i in sorted(cnts):
        # print(lmax,rmax)
        for ind in cnts[i]:
            if lmax[ind]==l[ind] and rmax[ind]==r[ind]:
                ans[ind]=mx
            else:
                return "NO"
        for ind in cnts[i]:
            for j in range(0,ind):
                rmax[j]+=1
            for j in range(len(l)-1,ind,-1):
                lmax[j]+=1
        mx-=1
    print("YES")
    print(*ans)
    return ''


n=input()
l=list(map(int,input().strip().split()))
r=list(map(int,input().strip().split()))
print(f(l,r))