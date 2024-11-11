import sys
input = sys.stdin.readline
N=int(input())
A=[]
C=[]
D=[]
for i in range(N):
    a,b=map(int,input().split())
    c,d=min(a,b),max(a,b)
    A.append((c,d))
    C.append(c)
    D.append(d)
A.sort()
#print(A,C,D,si,ti)
if N==1:
    print(0)
    sys.exit()
ans=(max(C)-min(C))*(max(D)-min(D))
cur=max(C)
ma=min(D)
T=10**19
for a,b in A:
    if a>ma:
        T=min(T,cur-ma)
        break
    T=min(T,cur-a)
    cur=max(cur,b)
print(min(ans,(max(D)-min(C))*T))