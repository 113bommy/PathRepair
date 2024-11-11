t=int(input())
while (t>0):
    t=t-1
    n=int(input())
    a=list(map(int,input().split()))
    s=0
    for i in range(1,n):
        s+=max(a[i-1]-a[i],0)
    print(s)    