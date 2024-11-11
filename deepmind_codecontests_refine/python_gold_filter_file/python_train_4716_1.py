import sys
input = sys.stdin.readline

q=int(input())
for tests in range(q):
    n,k=map(int,input().split())
    S=input().strip()

    MIN=min(1<<k,n+1)
    
    BLIST=[0]*MIN
    ALL=(1<<k)-1

    right=n-1
    left=n-1
    NOW=0
    
    while right>=k-1 and left>=0:
        while right-left<k and right>=k-1 and left>=0:
            #print(right,left,NOW)
            if S[left]=="0":
                if right-left<20:
                    NOW+=1<<(right-left)
                    left-=1
                else:
                    nright=min(left+20,right-1)
                    NOW>>=right-nright
                    right=nright
            else:
                left-=1

        #print(right,left,NOW)

        if NOW<MIN and right-left==k:
            BLIST[NOW]=1
        NOW>>=1
        right-=1

        #print("!",right,left,MIN)

    #print(BLIST)

    for i in range(MIN):
        if BLIST[i]==1:
            continue
        else:
            print("YES")
            print(bin(i)[2:].zfill(k))
            break
    else:
        print("NO")
