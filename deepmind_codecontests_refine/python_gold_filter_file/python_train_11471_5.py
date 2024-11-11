q=int(input())
for i in range(q):
    n=int(input())
    a=[0]*(n*4)
    a[0:n*4]=map(int,input().split())
    a.sort()
    w=a[0]*a[n*4-1]
    e=0
    for o in range(n):
        if (a[o*2]!=a[o*2+1]) or (a[n*4-o*2-1]!=a[n*4-o*2-2]) or (a[o*2]*a[n*4-o*2-1]!=w):
            e=1
            break
    if e==1:
        print('No')
    else:
        print('Yes')