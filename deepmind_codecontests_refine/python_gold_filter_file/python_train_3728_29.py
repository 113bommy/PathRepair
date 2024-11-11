from itertools import product

X, Y, Z, K = list(map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

AB = [a + b for a, b in product(A, B)]
AB.sort(reverse=True)

ABC = [ab + c for ab, c in product(AB[:K], C)]
ABC.sort(reverse=True)

for abc in ABC[:K]:
    print(abc)