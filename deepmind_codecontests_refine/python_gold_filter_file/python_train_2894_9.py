n, q = map(int, input().split())
ko=[[] for i in range(n)]
for i in range(n-1):
    a,b=map(int, input().split())
    ko[a-1].append(b-1)
ans=[0]*n
for i in range(q):
    a,b=map(int, input().split())
    ans[a-1]+=b
nex=[0]
while nex:
    p=nex.pop()
    for i in ko[p]:
        ans[i]+=ans[p]
    nex+=ko[p]
print(*ans)