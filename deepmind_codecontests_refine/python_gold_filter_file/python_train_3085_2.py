def main():
    n,m=map(int,input().split())
    costs=list(map(int,input().split()))
    ways=[[] for _ in range(n)]
    for _ in range(m):
        a,b=map(int,input().split())
        ways[a-1].append(b-1)
        ways[b-1].append(a-1)
    s=set()
    ans=0
    ad=s.add
    for i,cost in enumerate(costs):
        if i in s:
            continue
        else:
            Q=[i]
            ad(i)
            m=cost
            while Q:
                new=Q.pop()
                for j in ways[new]:
                    if j not in s:
                        ad(j)
                        Q.append(j)
                        m=min(m,costs[j])
            ans+=m
    print(ans)
main()
