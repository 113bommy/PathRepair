for t in range(int(input())):
    n,m,x,y=map(int,input().split())
    cost=0
    for i in range(n):
        b=input()
        j=0
        while j<m:
            if y<2*x:
                if j!=m-1:
                    if b[j]==b[j+1]==".":
                        cost+=y
                        j+=1
                    elif b[j]==".":
                        cost+=x
                else:
                    if b[j]==".":
                        cost+=x
            else:
                if b[j]==".":
                    cost+=x
            j+=1
    print(cost)