for _ in range(int(input())):	
    x,y,n=map(int,input().split())

    if n%x>=y:
        print(n-((n%x)-y))
    
    else:
        k=n%x
        s=x-y+k
        print(n-s)

