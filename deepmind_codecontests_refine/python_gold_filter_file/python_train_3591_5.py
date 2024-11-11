import sys
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def input(): return sys.stdin.readline().strip()
# ///==========MAIN=============///
n,m=get_ints()
if m==1:
    if n==1:
        print(1)
    else:
        print(m+1)
elif m==n:
    print(m-1)
else:
    if (m-1)>=(n-m):
        print(m-1)
    else:
        print(m+1)
