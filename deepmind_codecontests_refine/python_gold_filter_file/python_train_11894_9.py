for _ in range(int(input())):
    N=int(input())
    if N==2 or N==3:
        print(-1)
    elif N==4:
        L=[3,1,4,2]
        print(*L)
    elif N==5:
        L=[3,1,5,2,4]
        print(*L)
    else:
        odd=[]
        even=[]
        for i in range(1,N+1):
            if i%2==0:
                even.append(i)
            else:
                odd.append(i)
        L=odd[::-1]+even[::]
        for i in range(N):
            if L[i]==1 and L[i+1]==2:
                L.insert(i+1,4)
                break
        for i in range(N,0,-1):
            if L[i]==4:
                L[i]=-1
                break
        for i in range(N+1):
            if L[i]>0:
                print(L[i],end=" ")
        print()
