from collections import deque
import sys

N,K=map(int,input().split())
A=list(map(int,input().split()))
M=10**9+7

if N==K:
    T=1
    for a in A:
        T=(T*a)%M
    print(T)
    sys.exit()
elif max(A)<0 and K%2==1:
    A.sort(reverse=True)
    T=1
    for i in range(K):
         T=(T*A[i])%M
    print(T)
    sys.exit()
    
U=list(map(lambda x:max(x,0),A))
U.sort(reverse=True)
U=deque(U)

V=list(map(lambda x:min(x,0),A))
V.sort()
V=deque(V)

T=1
Y=0
while Y<K:
    x1,x2=U[0],U[1]
    y1,y2=V[0],V[1]

    if Y==K-1 or x1*x2>=y1*y2:
        Y+=1
        T=(T*x1)%M
        _=U.popleft()
        U.append(0)
    else:
        Y+=2
        T=(T*y1*y2)%M
        _=V.popleft()
        _=V.popleft()
        V.append(0)
        V.append(0)
print(T)
