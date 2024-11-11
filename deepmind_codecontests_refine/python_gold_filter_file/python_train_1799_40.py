# Author : Pratyaydeep↯Ghanta
import sys
inp=sys.stdin.buffer.readline
inar=lambda: list(map(int,inp().split()))
inin=lambda: int(inp())
inst=lambda: inp().decode().rstrip('\n\r')
# Am I debugging, check if I'm using same variable name in two places

from bisect import bisect
st=[1]
n=1e18
rem=n
ans=0
i=1
prev=0
used=0
while(rem>0):
    if i*i+2*prev<=rem:
        rem-=i*i+2*(prev)
        ans+=1
        prev=i*i+2*prev
        used+=prev
        i*=2
        st.append(used)
    else:
        break

_T_=inin()
for _t_ in range(_T_):
    n=inin()
    print(bisect(st,n)-1)
