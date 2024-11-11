for i in range(int(input())):
    n=int(input())
    q=list(input())
    w=list(input())
    e=[]
    r=[]
    for j in range(n):
        if q[j]!=w[j]:
            e.append(q[j])
            r.append(w[j])
    if len(e)==2 and len(set(e))==1 and len(set(r))==1:
        print('YES')
    else:
        print('NO')