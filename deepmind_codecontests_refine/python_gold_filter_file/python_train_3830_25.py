import sys
input = sys.stdin.readline

N,K=map(int,input().split())
A=sorted(map(int,input().split()))

M=[]
Z=[]
P=[]

for a in A:
    if a<0:
        M.append(-a)
    elif a==0:
        Z.append(a)
    else:
        P.append(a)

M.reverse()

MINUS=len(M)*len(P)
PLUS=len(P)*(len(P)-1)//2+len(M)*(len(M)-1)//2
ZERO=N*(N-1)//2-PLUS-MINUS

if MINUS<K and K<=MINUS+ZERO:
    print(0)
    sys.exit()

if K<=MINUS:
    OK=10**18
    NG=0

    while OK-NG>1:
        mid=(OK+NG)//2

        ANS=0
        NOW=len(P)-1

        for i in range(len(M)):
            while NOW>=0 and mid<M[i]*P[NOW]:
                NOW-=1
            ANS+=len(P)-NOW-1

        if ANS>=K:
            NG=mid

        else:
            OK=mid

    print(-OK)

else:
    OK=0
    NG=10**18
    K-=MINUS+ZERO

    while NG-OK>1:
        mid=(OK+NG)//2

        ANS=0
        NOW=len(P)-1

        for i in range(len(P)):
            while NOW>0 and mid<=P[i]*P[NOW]:
                NOW-=1
            ANS+=max(0,NOW-i)

        NOW=len(M)-1

        for i in range(len(M)):
            while NOW>0 and mid<=M[i]*M[NOW]:
                NOW-=1
            ANS+=max(0,NOW-i)

        if ANS>=K:
            NG=mid

        else:
            OK=mid

    print(OK)
