N,K,S=[int(i) for i in input().split()]
res=[10**9-1]*N
for i in range(K):
    res[i]=S
print(*res)
