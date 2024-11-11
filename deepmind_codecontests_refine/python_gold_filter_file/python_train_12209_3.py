t=int(input())
for i in range(t):
    l=input()
    L=l.split()
    n=int(L[0])
    T=int(L[1])
    c=input()
    A=c.split()
    for i in range(n):
        A[i]=int(A[i])
    s0=set()
    s1=set()
    s1.add(T-A[0])
    ch="1 "
    if T%2==1:
        for i in range(1,n):
            if A[i] in s1:
                ch+="0 "
                s0.add(T-A[i])
            else:
                ch+="1 "
                s1.add(T-A[i])
    else:
        sex=0
        for i in range(1,n):
                if A[i]==T//2 and sex==0:
                    sex=1
                    ch+="0 "
                elif A[i]==T//2 and sex==1:
                    sex=0
                    ch+="1 "
                elif A[i] in s1:
                    ch+="0 "
                    s0.add(T-A[i])
                else:
                    ch+="1 "
                    s1.add(T-A[i])
        
        
        
    print(ch)