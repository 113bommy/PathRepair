t=int(input())
for i in range (t):
    n=int(input())
    l=[int(x) for x in input().split()]
    g=l.copy()
    g.sort()
    g.reverse()
    j=0
    dog=0
    while j<=n-3:
        a=l.index(g[j])
        if a!=0 and a!=(n-1):
            lef=-1
            ri=-1
            for k in range (a):
                if l[k]<g[j]:
                    lef=k
                    break
            temp=l[a+1:]
            for k in range (n-a-1):
                if temp[k]<g[j]:
                    ri=k+1+a
                    break
            if lef!=-1 and ri!=-1:
                print("YES")
                print(lef+1,a+1,ri+1)
                dog=1
                break     
        j=j+1       
    if dog==0:
        print("NO")