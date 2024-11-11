t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    f=False
    l=[]
    for i in range(n):
        l1=[]
        for i in range(2):
            l2=[int(i) for i in input().split()]
            l1.append(l2)
        l.append(l1)
    for e in l:
        if e[1][0]==e[0][1]:
            f=True
            break
    if m%2==1:
        f=False
    if f:
        print("YES")
    else:
        print("NO")
        