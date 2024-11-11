n,x=map(int, input().split())
if x==1 or x==2*n-1:print('No')
else:
    print('Yes')
    a=list(range(1,2*n))
    b=[]
    b.append(a.pop(x))
    b.append(a.pop(x-1))
    b.append(a.pop(x-2))
    for i in a[:n-2]+b+a[n-2:]:
        print(i)