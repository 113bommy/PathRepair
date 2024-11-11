for _ in range(int(input())):
    n,m,x,y=map(int,input().split())
    l=[]
    for i in range(n):
        lst=input()
        lst+='*'
        l.append(lst)
    cost=0
    for i in range(n):
        k=0
        s=-1
        while(k<=m):
            while(l[i][k]=='.'):
                k+=1
            z=k-s-1
            if(z>0 and 2*x>y):
                cost+=((z//2)*y)
                cost+=((z%2)*x)
            elif(z>0 and 2*x<=y):
                cost+=z*x
            s=k
            k+=1
    print(cost)