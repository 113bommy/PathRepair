N,K,S=map(int,input().split())

if S==10**(9):
    ans=[S-1]*N
else:
    ans=[10**(9)]*N
for i in range(K):
    ans[i]=S
print(*ans)