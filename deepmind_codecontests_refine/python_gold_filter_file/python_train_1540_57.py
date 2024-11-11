n,m=map(int,input().split())
A=list(map(int,input().split()))
print(n-sum(A) if n-sum(A)>=0 else -1)