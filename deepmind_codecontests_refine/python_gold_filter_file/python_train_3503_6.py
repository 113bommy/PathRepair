'''def f(n):
    if n==1:
        return 0
    if n==2:
        if k==2:
            return min(a,b)
        return a
    if n%k==0:
        return b+f(n//k)
    return a*(n%k)+f(n-n%k)
'''
n=int(input())
k=int(input())
a=int(input())
b=int(input())
m=n
ans=0
if n>=k and k>1:
    while n!=1:

        ans+=(n%k)*a
        n -= n % k
        ans+=min(b,(n-n//k)*a)
        n//=k
        if n<k:
            ans+=(n-1)*a
            break
    print(min(ans,(m-1)*a))
else:
    print((n-1)*a)