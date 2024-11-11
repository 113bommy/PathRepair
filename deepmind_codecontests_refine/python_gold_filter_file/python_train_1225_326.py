n,k=map(int,input().split())
nl=list(map(int,input().split()))
nl.sort()
print(sum(nl[:k]))
