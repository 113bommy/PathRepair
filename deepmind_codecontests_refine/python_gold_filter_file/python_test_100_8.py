for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    l.sort()
    m=min(l)
    if n==1:
        print(l[0])
    else:
        for i in range(n-1):
            m=max(m,l[i+1]-l[i])

        print(m)

    

    