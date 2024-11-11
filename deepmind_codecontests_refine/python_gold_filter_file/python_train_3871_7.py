a,b=map(int,input().split())
z=sorted(map(int,input().split()))
def ok(mid):
    clk=0
    for i in range(a//2,a):
        clk+=max(0,mid-z[i])
        if clk>b:return False
    return True
def bin_s():
    lo,hi,ans=1,2*int(1e9),0
    while lo<=hi:
        mid=(lo+hi)//2
        if ok(mid):ans=mid;lo=mid+1
        else:hi=mid-1
    return ans
print(bin_s())