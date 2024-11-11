from itertools import product
X,Y,Z,K = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
C = list(map(int,input().split()))
AB = sorted([a+b for a,b in product(A,B)],reverse=True)[:K]
ans = sorted([a+b for a,b in product(AB,C)],reverse=True)[:K]
for i in ans:
    print(i)