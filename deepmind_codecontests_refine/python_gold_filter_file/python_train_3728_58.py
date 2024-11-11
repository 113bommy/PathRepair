X,Y,Z,K=map(int,input().split())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=list(map(int,input().split()))

from itertools import product
D=sorted([a+b for a,b in product(A,B)],reverse=True)
D=D[:K]
E=sorted([d+c for d,c in product(D,C)],reverse=True)
for i in range(K):
    print(E[i])
