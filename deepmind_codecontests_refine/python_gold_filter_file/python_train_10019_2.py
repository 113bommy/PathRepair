t=int(input())
for i in range(t):
    n=int(input())
    p=list(map(int,input().split()))
    flg=0
    for j in range(n-1):
        if p[j]-p[j+1]<=-2:flg=1;break
    if flg:print("No")
    else:print("Yes")
