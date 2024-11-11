#######puzzleVerma#######


import sys
import math
mod = 10**9+7


LI=lambda:[int(k) for k in input().split()]
SLI=lambda:[str(k) for k in input().split()]
input = lambda: sys.stdin.readline().rstrip()
IN=lambda:int(input())
S=lambda:input()
r=range

def match(ind):
    p=ll-1-ind
    if s[p]=="?":
        tr[ind]=tr[2*ind+1]+tr[2*ind+2]
    elif s[p]=="0":
        tr[ind]=tr[2*ind+2]
    else:
        tr[ind]=tr[2*ind+1]
    return tr




k=IN()
s=S()
s=list(s)
q=IN()
ll=2**k-1
tr=[0]*ll
for i in r(ll):
    ind=ll-1-i
    if i<2**(k-1):
        if s[i]=="?":
            tr[ind]=2
        else:
            tr[ind]=1
    else:
        if s[i]=="?":
            tr[ind]=tr[2*ind+1]+tr[2*ind+2]
        elif s[i]=="0":
            tr[ind]=tr[2*ind+2]
        else:
            tr[ind]=tr[2*ind+1]

for i in r(q):
    p,c=SLI()
    p=int(p)
    p-=1
    ind=ll-1-p
    if p<2**(k-1):
        if c=="?":
            tr[ind]=2
        else:
            tr[ind]=1
    else:
        if c=="?":
            tr[ind]=tr[2*ind+1]+tr[2*ind+2]
        elif c=="0":
            tr[ind]=tr[2*ind+2]
        else:
            tr[ind]=tr[2*ind+1]
    while ind:
        ind-=1
        ind//=2
        tr=match(ind)
    s[p]=c
    print(tr[0])


    