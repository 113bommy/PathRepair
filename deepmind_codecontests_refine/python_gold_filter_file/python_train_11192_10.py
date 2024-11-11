a,b=map(int,input().split())

s=sorted(list(map(int,input().split())))
z=list(map(int,input().split()))

def f(s,x):
    hi=len(s)-1
    lo=0
    ans=0
    while lo<=hi:
        mid = (hi+lo)//2
        if s[mid]<=x:
            ans=mid+1
            lo=mid+1
        else:
            hi=mid-1

    return ans


for n in z:
    print(f(s,n),end=' ')