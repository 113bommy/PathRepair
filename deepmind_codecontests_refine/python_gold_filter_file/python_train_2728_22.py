for w in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    mi=min(a)
    ma=max(a)
    l=[]
    ans=0
    c=0
    if(ma-mi>=n):
        print("YES")
        print(min(a.index(mi)+1,a.index(ma)+1),max(a.index(mi)+1,a.index(ma)+1))
    elif(ma-mi<2):
        print("NO")
    else:
        for i in range(n-1):
            if(abs(a[i+1]-a[i])>=2):
                ans=1
                l.append(i+1)
                l.append(i+2)
                break
        if(ans==0):
            print("NO")
        else:
            print("YES")
            print(l[0],l[1])