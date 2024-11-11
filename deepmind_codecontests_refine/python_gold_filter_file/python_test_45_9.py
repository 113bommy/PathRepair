t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    s=1
    for i in range(n-1):
        if a[i]==0 and a[i+1]==0:
            s=-1
            break
    if s!=-1:
        for i in range(1,n):
            if a[i]==1 and a[i-1]==1:
                s+=5
            elif a[i]==1:
                s+=1
    if a[0]==1 and s!=-1:
        s+=1
    print(s)
