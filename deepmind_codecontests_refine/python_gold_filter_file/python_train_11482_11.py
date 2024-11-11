t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    if len(set(a))==1:
        print("NO")
    else:
        print("YES")
        for i in range(n):
            if a[i]!=a[0]:
                b=i+1
                break
        c=[]
        for i in range(1,n):
            if a[i]!=a[0]:
                c.append([1,i+1])
            else:
                c.append([b,i+1])
        for i in range(len(c)):
            print(*c[i])