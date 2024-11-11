n,k = map(int,input().split())
F = list(map(int,input().split()))
F.sort()
print(sum(F[:k]))