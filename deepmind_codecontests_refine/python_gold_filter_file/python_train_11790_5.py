for _ in range(int(input())):
    n=int(input())
    a=[]
    for i in range(n):
        b=[int(j) for j in input().split()]
        a.append(b[1:])
    b=[]
    c=[]
    for i in range(n):
        b.append(0)
        c.append(0)
    for i in range(n):
        for j in range(len(a[i])):
            if b[a[i][j]-1]==0:
                b[a[i][j]-1]=1
                c[i]=1
                break
    if 0 in b:
        print('IMPROVE')
        print(c.index(0)+1,b.index(0)+1)
    else:
        print('OPTIMAL')
