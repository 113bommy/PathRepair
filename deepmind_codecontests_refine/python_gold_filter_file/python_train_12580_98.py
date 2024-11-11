n,k=map(int,input().split())
l=list(map(int,input().split()))
l.sort(reverse=1)
print(sum(l[:k]))