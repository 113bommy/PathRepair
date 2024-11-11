n,k=map(int,input().split())
a=list(map(int,input().split()))
if k>n:
    print('-1')
else:
    a=sorted(a)
    k=a[len(a)-k]
    print(k,end=' 0')