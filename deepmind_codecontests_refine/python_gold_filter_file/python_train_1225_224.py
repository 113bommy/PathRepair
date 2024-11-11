n, k = map(int,input().split())
m = list(map(int,input().split()))

m.sort()

print(sum(m[:k]))