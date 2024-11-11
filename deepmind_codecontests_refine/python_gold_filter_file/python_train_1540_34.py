n,m=map(int,input().split())
l=list(map(int,input().split()))
print(n-sum(l) if n-sum(l)>=0 else -1)