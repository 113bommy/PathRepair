q=int(input())
for o in range(q):
    n=int(input())
    a=list(map(int,input().split()))
    pos=n-1
    while pos>0 and a[pos]<=a[pos-1]:
        pos-=1
    while pos>0 and a[pos]>=a[pos-1]:
        pos-=1
    print(pos)