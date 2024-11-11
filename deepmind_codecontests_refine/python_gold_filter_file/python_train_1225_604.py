n,k=map(int,input().split())
p=list(map(int,input().split()))
ps=sorted(p)
print(sum(ps[:k]))
