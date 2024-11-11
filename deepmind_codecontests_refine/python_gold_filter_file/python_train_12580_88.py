n,m=map(int,input().split())
l=list(map(int,input().split()))
l.sort(reverse=True)
print(sum(l[:m]))