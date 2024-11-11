import sys

sys.setrecursionlimit(10**7)

def dfs(x):
    if seen[x-1]==0:
        uni[cnt].add(x)
        seen[x-1]=1
        for i in fri[x-1]:
            dfs(i)
    

n,m,k=map(int,input().split())

fri=[[] for i in range(n)]
blk=[set() for i in range(n)]

for i in range(m):
    a,b=map(int,input().split())
    fri[a-1].append(b)
    fri[b-1].append(a)

for i in range(k):
    c,d=map(int,input().split())
    blk[c-1].add(d)
    blk[d-1].add(c)


seen=[0 for i in range(n)]

uni=[]
cnt=0
for i in range(1,n+1):
    if seen[i-1]==0:
        uni.append(set())
        dfs(i)
        cnt+=1

seq=[0 for i in range(n)]

for unii in uni:
    for j in unii:
        cj=len(unii)-len(fri[j-1])-len(unii&blk[j-1])-1
        seq[j-1]=cj

print(*seq)