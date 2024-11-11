n,a,b=map(int,input().split())
H=[int(input()) for _ in range(n)]
r=10**10
l=0
while r-l>1:
    k=(l+r)//2
    if sum( max(0,(h-k*b-1)//(a-b)+1) for h in H)>k:
        l=k
    else:
        r=k

print(r)