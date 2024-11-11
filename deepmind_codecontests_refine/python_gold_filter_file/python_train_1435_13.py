n,m=map(int,input().split())
g=[[] for x in range(n)]
for c in range(m):
    a,b= map(int,input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)

ans_list=[-1]*n

queue=[0]

while queue:
    qi=queue.pop(0)
    for gi in g[qi]:
        if ans_list[gi]==-1:
            queue.append(gi)
            ans_list[gi]=qi

print("Yes")
for ans in ans_list[1:]:
    print(ans+1)