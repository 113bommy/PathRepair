a,b=list(map(int,input().split()))
# print(a,b)
mod=998244353
if a==1 or b==1:
    ans=4*(2**(max(a,b)-1))
else:
    ans=4*(2**(a+b-2))
print(ans%mod)