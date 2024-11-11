import sys
input=sys.stdin.readline
mod=998244353
n=int(input())
b=0
w=0
blank=0

def fact(n):
    res=1
    for i in range(1, n+1):
        res*=i
        res%=mod
    return res

ct=1
L=[]
leftb=True
rightb=True
for i in ' '*n:
    s=input().strip()
    L=[]
    for j in s:
        if j=='B':b+=1
        if j=='W':w+=1
        if j=='?':blank+=1
    if s=='BB' or s=='WW':ct=0
    if s=='??':ct*=2
    ct%=mod

    if s[0]=='W':leftb=False
    if s[0]=='B':rightb=False
    if s[1]=='W':rightb=False
    if s[1]=='B':leftb=False

# print(leftb, rightb)
res=0
if abs(b-w)<=blank:
    r=(blank-abs(b-w))//2
    comb=fact(blank)*pow(fact(blank-r), mod-2, mod)*pow(fact(r), mod-2, mod)
    comb%=mod
    # print(blank, r, comb, ct)
    if leftb and rightb:
        res=comb-ct+2
    elif leftb or rightb:
        res=comb-ct+1
    else:
        res=comb-ct

print(res)