for gg in range(int(input())):
    a,b,n,m=map(int,input().split())
    if(a+b<n+m):
        print("NO")
        continue
    else:
        if(m>min(a,b)):
            print("NO")
        else:
            print("YES")
            
        