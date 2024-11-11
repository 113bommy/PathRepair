n,k = map(int,input().split())
v = list(map(int,input().split()))
v.sort()
print(sum(v[:k]))