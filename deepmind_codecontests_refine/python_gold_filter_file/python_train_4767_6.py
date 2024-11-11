k,q=map(int,input().split())
d=list(map(int,input().split()))
for i in range(q):
    n,x,m=map(int,input().split())
    l=[i%m if i%m!=0 else m for i in d]
    print(n-1-(x+((n-1)//k)*sum(l)+sum(l[:(n-1)%k]))//m+x//m)
