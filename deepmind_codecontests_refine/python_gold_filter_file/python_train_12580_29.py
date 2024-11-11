n,k=map(int,input().split())
l=sorted(list(map(int,input().split())))
l.reverse()
print(sum(l[:k]))