a,b=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
print(sum(l[a-b:]))