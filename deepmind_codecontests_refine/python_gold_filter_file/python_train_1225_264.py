n,k=map(int,input().split())
p=list(map(int,input().split()))
p2=sorted(p)
print(sum(p2[:k]))
