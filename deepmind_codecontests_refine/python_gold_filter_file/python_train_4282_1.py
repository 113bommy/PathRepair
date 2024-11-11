arr =[]
cap = 0
def chck (k):
    ans=0
    for i in arr:
        if (i<k):
            return False
        ans=ans+i-k
    if (ans>=cap):
        return True
    return False
def bsrch (strt,ed):
    ans=-1
    while (strt<=ed):
        mid=(strt+ed)//2
        if (chck(mid)):
            ans=mid
            strt=mid+1
        else:
            ed=mid-1
    return ans

n,cap=input().split()
n=int(n)
cap=int(cap)
arr = list(map(int,input().split()))
print(bsrch(0,1000000000))