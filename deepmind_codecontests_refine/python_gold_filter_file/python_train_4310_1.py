n,k=list(map(int,input().split()))
if (n*n-n)//2<=k:
    print("no solution")
else:
    x=0
    y=0
    store=[]
    count=0
    store.append(str(x)+' '+str(y))
    while len(store)<n:
        y+=1
        store.append(str(x)+' '+str(y))
    for j in store:
        print(j)   