t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    sum1=a[0]+a[1]
    found=0
    for i in range(2,n):
        if sum1<=a[i]:
            found=1
            break
    if found!=1:
        print("-1")
    else:
        print(1,2,i+1)
