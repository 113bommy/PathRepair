import sys
q=int(input())
for i in range(q):
    n,m=[int(j) for j in sys.stdin.readline().split()]
    c=[0]*m
    d=[0]*n
    for j in range(n):
        a=input().split()
        for k in range(len(a)):
            if a[k]=='1':
                c[k]=1
                d[j]=1
    t1=c.count(0)
    t2=d.count(0)
    ol=min(t1,t2)
    if ol%2==0:
        print('Vivek')
    else:
        print('Ashish')

