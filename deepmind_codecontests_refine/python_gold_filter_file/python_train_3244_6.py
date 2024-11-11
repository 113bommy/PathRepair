for _ in range(int(input())):
    n=int(input())
    L=[int(x)%3 for x in input().split()]
    X=[0,0,0]
    
    for x in L:
        if x==0:
            X[0]+=1
        elif x==1:
            X[1]+=1
        else:
            X[2]+=1
    
    if X[1]==X[2]:
        print(X[0]+X[1])
    elif X[1]>X[2]:
        print(X[0]+X[2]+(X[1]-X[2])//3)
    else:
        print(X[0]+X[1]+(X[2]-X[1])//3)
    
    
        
    
