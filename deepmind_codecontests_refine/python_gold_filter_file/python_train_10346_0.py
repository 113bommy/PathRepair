n,k = map(int, input().split())
maxK=-10**10
for i in range(n):
    f,t = map(int, input().split())
    if t>k:
        maxK = max(maxK,f-(t-k))
    else:
        maxK = max(maxK, f )
print(maxK)