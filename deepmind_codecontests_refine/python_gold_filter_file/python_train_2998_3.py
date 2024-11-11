n=int(input())
g=[[] for _ in range(n)]
for i in range(n-1):
    a,b=map(int,input().split())
    g[a-1].append((b-1,i))

vc=[0] * n
ec=[-1]*(n-1)
for p,ci in enumerate(g):
    color = 1
    for c, i in ci:
        if vc[p] == color:
            color += 1
        vc[c] = color
        ec[i] = color
        color += 1
        

print(max(ec))
for i in range(n-1):
    print(ec[i])
