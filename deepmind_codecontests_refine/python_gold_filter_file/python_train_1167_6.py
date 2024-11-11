for _ in range(int(input())):
    n=int(input())
    l=[]
    for i in range(n):
        a=list(int(x) for x in input().split())
        a[0],a[1]=a[1],a[0]
        l.append(a)
    l.sort()
    for i in range(len(l)):
        l[i][0],l[i][1]=l[i][1],l[i][0]
    a,b=0,0
    st=""
    ans=0
    for i in range(len(l)):
        if(a<=l[i][0] and b<=l[i][1]):
            d="R"*(l[i][0]-a)
            e="U"*(l[i][1]-b)
            st=st+d+e
            a=l[i][0]
            b=l[i][1]
            ans+=1
        else:
            ans=-1
            break;
    if(ans==n):
        print("YES")
        print(st)
    else:
        print("NO")
        