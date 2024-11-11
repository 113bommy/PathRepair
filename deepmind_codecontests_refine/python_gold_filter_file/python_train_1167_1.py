t=int(input())
for _ in range(t):
    ans=""
    f=0
    x=0
    y=0
    s=[]
    n=int(input())
    for i in range(n):
        a,b=map(int,input().split())
        s.append((a,b))
        s.sort()
    for i in s:
        if i[0]>=x and i[1]>=y:
            ans+=("R"*(i[0]-x))
            ans+=("U"*(i[1]-y))
            x=i[0]
            y=i[1]
        else:
            f=1 
            break
    if f:
        print("NO")
    else:
        print("YES")
        print(ans)