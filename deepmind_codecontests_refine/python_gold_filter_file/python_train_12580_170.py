n,k = map(int,input().split())
a = sorted(map(int,input().split()))[::-1]
print(sum(a[:k]))