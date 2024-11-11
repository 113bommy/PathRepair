def f(l):
    n,k = l
    return [min(1,k,n-k),min(k<<1,n-k)]

l = list(map(int,input().split()))
print(*f(l))
