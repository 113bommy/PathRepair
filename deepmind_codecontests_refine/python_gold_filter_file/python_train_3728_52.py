X,Y,Z,K = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
C = list(map(int,input().split()))

import itertools
AB = [a + b for a, b in itertools.product(A,B)]
AB.sort(reverse=True)
ABC = [ab + c for ab, c in itertools.product(AB[:3000],C)]
ABC.sort(reverse=True)
for i in range(K):
    print(ABC[i])
