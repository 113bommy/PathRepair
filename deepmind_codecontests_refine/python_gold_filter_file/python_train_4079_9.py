t=int(input())
while t>0:
    t-=1
    n=int(input())
    b=[]
    for i in range(n):
        a=[int(x) for x in input().split()]
        b.append(a)
    #XYLDRU
    L=[]
    R=[]
    U=[]
    D=[]
    for a in b:
        if a[2]==0:
            L.append(a[0])
        if a[3]==0:
            D.append(a[1])
        if a[4]==0:
            R.append(a[0])
        if a[5]==0:
            U.append(a[1])
    L.sort(reverse=True)
    R.sort()
    U.sort(reverse=True)
    D.sort() 
    if len(L)==0:
        L.insert(0,-100000)
    if len(U) ==0:
        U.insert(0,-100000)
    if len(R)==0:
        R.insert(0,100000)
    if len(D) ==0:
        D.insert(0,100000)
    if L[0]>R[0] or U[0]>D[0]:
        print(0)
        continue
    
    print(1,L[0],U[0])    
        
        