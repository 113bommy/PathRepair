import sys
input = sys.stdin.readline

n=int(input())
A=list(map(int,input().split()))
A.sort()

from collections import Counter
C=Counter(A)
dou=0

for c in C:
    dou+=C[c]-1

    if C[c]>=2 and C[c-1]!=0:
        print("cslnb")
        sys.exit()
        
if dou>=2:
    print("cslnb")
    sys.exit()

ANS=0
for i in range(n):
    if A[i]<i:
        print("cslnb")
        sys.exit()
    ANS+=(A[i]-i)%2

if ANS%2==0:
    print("cslnb")
    sys.exit()
else:
    print("sjfnb")
    sys.exit()
    
    
