n,k=map(int,input().split())
l=sorted(map(int,input().split()) ,reverse=True)
print(sum(l[:k]))