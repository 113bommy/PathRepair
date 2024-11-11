n, q=input().split()
n=int(n)
q=int(q)
p0=0
Ans=[]
Q=[(0, True)]
App=[set() for i in range(n+1)]
t=1
ans=0
for i in range(q):
    q, p=input().split()
    p=int(p)
    if q=='1':
        App[p].add(t)
        Q.append([p, False])
        t+=1
        ans+=1
    elif q=='2':
        for i in App[p]:
            Q[i][1]=True
        ans-=len(App[p])
        App[p]=set()
    elif q=='3':
        if p>p0:
            for i in range(p0, p+1):
                if Q[i][1]==False:
                    Q[i][1]=True
                    App[Q[i][0]].remove(i)
                    ans-=1
            p0=p
    Ans.append(ans)
print('\n'.join(map(str, Ans)))


