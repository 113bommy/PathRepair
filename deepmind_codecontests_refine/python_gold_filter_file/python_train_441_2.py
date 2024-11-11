t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    c=list(map(int,input().split()))
    l=[]
    l.append(a[0])
    for i in range(1,n):
        if(a[i]!=l[i-1] and a[i]!=l[0]):
            l.append(a[i])
        elif(b[i]!=l[i-1] and b[i]!=l[0]):
            l.append(b[i])
        elif(c[i]!=l[i-1] and c[i]!=l[0]):
            l.append(c[i])
    print(*l)