n,m=map(int,input().split())
l=list(map(int,input().split()))
l1=sorted(l)
print(sum(l1[:m]))