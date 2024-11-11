n=int(input())
a=list(map(int,input().split()))

a.sort()
l=len(a)
if l%2==0:
    k=l//2
    for i in range(k):
        print(a[i],a[k+i],sep=' ',end=' ');
else:
    k=(l-1)//2;
    print(a[0],sep=' ',end=' ');
    for i in range(k):
        print(a[l-1-i],a[i+1],sep=' ',end=' ');
