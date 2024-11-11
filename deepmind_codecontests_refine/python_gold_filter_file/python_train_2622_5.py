import sys
input = sys.stdin.readline

T = int(input())
for testcases in range(T):
    S=input().strip()
    LEN=len(S)

    zeros=0
    ANS=0

    for i in range(LEN):
        if S[i]=="0":
            zeros+=1
        else:

            for j in range(1,min(22,LEN-i+1)):
                k=int((S[i:i+j]),2)
                if k==0:
                    continue
                #print(i,j,k)
                if zeros>=k-j:
                    ANS+=1

            zeros=0

    print(ANS)

        

    
