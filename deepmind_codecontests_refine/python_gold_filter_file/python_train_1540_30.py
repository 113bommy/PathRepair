n,m=map(int,input().split())
a=list(map(int,input().split()))
s=sum(a)
print(max(n-s,-1))