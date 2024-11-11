# --------------------------------#
#-----------<HajLorenzo>-----------
#Most Important Thing About Life
#Is Loving What You Do...
# --------------------------------#

import sys
input=sys.stdin.readline
n=int(input())
dfx=list(map(int,input().split()))
index=[0,n-1]
for i in range(n-1):
    if(dfx[i+1]>dfx[i]):
        index[0]=i+1
    else:
        break
for i in range(n-1,-1,-1):
    if(dfx[i-1]>dfx[i]):
        index[1]=i-1
    else:
        break
print("YES" if(len(set(dfx[index[0]:index[1]+1]))==1) else "NO")