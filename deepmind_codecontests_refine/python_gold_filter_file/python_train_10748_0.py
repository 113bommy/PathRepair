
        
for _ in range(int(input())):
    n,x=map(int,input().split())
    a=list(map(int,input().split()[:n]))
    e=sum(1 for i in a if i%2==0)
    o=sum(1 for i in a if i%2==1)
    if x==n:
        if sum(a)%2==1:
            print("YES")
        else:
            print("NO")
    else:
        if o==0:
            print("NO")
        elif e==0 and x%2==0:
            print("NO")
        else:
            print("YES")