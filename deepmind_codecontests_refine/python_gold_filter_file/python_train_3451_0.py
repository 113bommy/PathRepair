import sys
import math
input=sys.stdin.readline
def areAllBitsSet(n):
    if (n == 0):
        return False
    if (((n + 1) & n) == 0):
        return True
    return False
 
n=int(input())
if(areAllBitsSet(n)):
    print(0)
else:
    cnt=0
    st=[]
    while(not(areAllBitsSet(n))):
        r=math.floor(math.log(n,2))
        st.append(r+1)
        n=n^(pow(2,r+1)-1)
        cnt+=1
        if(not(areAllBitsSet(n))):
            n+=1
            cnt+=1
    print(cnt)
    print(*st)