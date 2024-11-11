N,X=map(int,input().split())
ans=0
def rec(x,n):
    global ans
    if n==0:
        if x>=1:
            ans+=1
    elif x>2**(n+1)-2:
        ans+=(2**n-1+1)
        rec(x-(2**(n+1)-1),n-1)
    else:
        rec(x-1,n-1)

rec(X,N)
print(ans)
