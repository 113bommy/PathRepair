import sys
input = sys.stdin.readline
import heapq
from collections import defaultdict

N=int(input())
A=[0]+list(map(int,input().split()))

def Nextstring(nowlength,nextlength):
    if nextlength>nowlength:
        while -USELIST[0]>nowlength:
            dis=-heapq.heappop(USELIST)
            del NOWSTR[dis]
        nowlength=nextlength

    else:
        while -USELIST[0]>nextlength:
            dis=-heapq.heappop(USELIST)
            del NOWSTR[dis]

        if NOWSTR[nextlength]<mid-1:
            
            if NOWSTR[nextlength]==0:
                NOWSTR[nextlength]+=1
                heapq.heappush(USELIST,-nextlength)
                nowlength=nextlength
            else:
                NOWSTR[nextlength]+=1
                nowlength=nextlength

        else:
            klength=nextlength
            while NOWSTR[klength]==mid-1:
                if klength in NOWSTR:
                    del NOWSTR[klength]
                klength-=1
                if mid!=1:
                    dis=-heapq.heappop(USELIST)
                    if dis in NOWSTR:
                        del NOWSTR[dis]

                if klength==0:
                    return -1

            if NOWSTR[klength]==0:
                NOWSTR[klength]+=1
                heapq.heappush(USELIST,-klength)
                nowlength=nextlength

            else:
                NOWSTR[klength]+=1
                nowlength=nextlength

    return 0

for i in range(N):
    if A[i]>=A[i+1]:
        MIN=2
        break
else:
    print(1)
    sys.exit()

from collections import Counter
MAX=max(Counter(A).values())+1

while MIN!=MAX:
    mid=(MIN+MAX)//2
    nowlength=0
    NOWSTR=defaultdict(int)
    USELIST=[10**6]

    for i in range(N):

        if Nextstring(A[i],A[i+1])==-1:
            MIN=mid+1
            break
        #print(mid,NOWSTR,USELIST)
    else:
        MAX=mid

print(MIN)