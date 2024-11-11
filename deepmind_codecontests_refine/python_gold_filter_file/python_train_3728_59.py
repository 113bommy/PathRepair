from itertools import product

X,Y,Z,K = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]
C = [int(i) for i in input().split()]

BC = [i+j for i,j in list(product(B,C))]
BC.sort(reverse=True)

ans = [i+j for i,j in list(product(BC[:min(3000, X*Y*Z)], A))]
ans.sort(reverse=True)

[print(ans[i]) for i in range(K)]
