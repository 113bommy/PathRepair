n,m=map(int,input().split())
n_names=list(map(str,input().split()))
m_names=list(map(str,input().split()))
q=int(input())
for i in range(q):
    res=""
    no=int(input())
    x=no%n
    y=no%m
    if x==0:
        res+=n_names[-1]
    else:
        res+=n_names[x-1]
    if y==0:
        res+=m_names[-1]
    else:
        res+=m_names[y-1]
    print(res)
