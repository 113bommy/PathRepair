t=int(input())

for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    f=0
    for i in range(2,len(a)):
        if a[0]+a[1]<=a[i]:
            f=1
            print("1 2",i+1)
            break
    if f==0:
        print(-1)

