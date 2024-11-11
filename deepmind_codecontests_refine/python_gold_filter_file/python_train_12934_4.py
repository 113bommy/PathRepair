import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from math import sqrt

t=int(input())
for tests in range(t):
    n=int(input())
    P=list(map(int,input().split()))
    C=list(map(int,input().split()))

    for i in range(n):
        P[i]-=1

    USE=[0]*n
    ANS=n

    for i in range(n):
        if USE[i]==1:
            continue

        cy=i
        CYCLE=[]

        while USE[cy]!=1:
            USE[cy]=1
            cy=P[cy]
            CYCLE.append(cy)

        #print(CYCLE)

        LEN=len(CYCLE)
        x=LEN
        xr=int(sqrt(x))+1
        LIST=[]

        for k in range(1,xr+1):
            if x%k==0:
                LIST.append(k)
                LIST.append(x//k)

        for l in LIST:
            if ANS<=LEN//l:
                continue
            COLORS=[-1]*(LEN//l)
            ind=0
            for k in range(LEN):
                if COLORS[ind]==-1:
                    COLORS[ind]=C[cy]
                elif COLORS[ind]==C[cy]:
                    True
                else:
                    COLORS[ind]=0
                    
                cy=P[cy]
                ind+=1
                if ind==LEN//l:
                    ind=0

            for c in COLORS:
                if c!=0:
                    ANS=LEN//l
                    break

            #print(CYCLE,l,COLORS)

    print(ANS)

            

        
            
        
