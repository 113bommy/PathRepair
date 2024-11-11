import sys
input = sys.stdin.readline

N=int(input())
A=list(map(int,input().split()))
mod=10**9+7

XOR=[0]
for a in A:
    XOR.append(XOR[-1]^a)

ZEROS=[0]
for xor in XOR:
    if xor==0:
        ZEROS.append(ZEROS[-1]+1)
    else:
        ZEROS.append(ZEROS[-1])

if XOR[-1]!=0:
    SUBJ=XOR[-1]
    SUBJ_LIST=[]

    for j in range(N+1):
        if XOR[j]==SUBJ:
            SUBJ_LIST.append(j)

    #print(SUBJ_LIST)

    ZERO=1
    NOW=0

    for i in range(len(SUBJ_LIST)):
        ZERO+=NOW*(ZEROS[SUBJ_LIST[i]]-ZEROS[SUBJ_LIST[i-1]])
        NOW+=ZERO

        #print(NOW,ZERO)

    print(ZERO%mod)

else:
    SET=set(XOR)
    
    from collections import defaultdict
    SUBJ=defaultdict(list)
    for j in range(1,N+1):
        SUBJ[XOR[j]].append(j)

    ANS=1<<(ZEROS[-1]-2)

    for subj in SUBJ:
        if subj==0:
            continue
        ZERO=1
        NOW=0

        for i in range(len(SUBJ[subj])):
            
            ZERO=(ZERO+NOW*(ZEROS[SUBJ[subj][i]]-ZEROS[SUBJ[subj][i-1]]))%mod
            NOW=(NOW+ZERO)%mod

        #print(ZERO,SUBJ[subj],subj)
        ANS=(ANS+NOW)%mod

    print(ANS%mod)