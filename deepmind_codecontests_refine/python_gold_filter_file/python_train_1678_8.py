for i in range(int(input())):
    a,v,l,r=map(int,input().split())
    ans=(a//v)-((r//v)-((l-1)//v))
    print(ans)
        
        