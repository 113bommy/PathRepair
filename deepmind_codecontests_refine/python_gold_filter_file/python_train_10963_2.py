import sys
input = sys.stdin.readline

n=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=[]

S=0
for i in range(n):
    C.append(A[i]*B[i])
    S+=C[i]

ANS=S

for i in range(n):
    
    XS=S
    ANS=max(ANS,XS)
    for j in range(i+1):
        if i-j>=0 and i+j<n:
            XS+=(A[i+j]-A[i-j])*(B[i-j]-B[i+j])
            ANS=max(ANS,XS)
        else:
            break

    if i>=1:
        XS=S-C[i-1]-C[i]+A[i-1]*B[i]+A[i]*B[i-1]
        ANS=max(ANS,XS)

        for j in range(1,i):
            if i-1-j>=0 and i+j<n:
                XS+=(A[i+j]-A[i-j-1])*(B[i-j-1]-B[i+j])
                ANS=max(ANS,XS)
            else:
                break

print(ANS)

        
    
        
