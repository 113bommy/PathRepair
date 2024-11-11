from itertools import product
x, y, z, k = map(int, input().split())
A = map(int, input().split())
B = map(int, input().split())
C = map(int, input().split())
AB = [sum(ab) for ab in product(A, B)]
AB.sort(reverse=True)
AB = AB[:k]
ABC = [sum(abc) for abc in product(AB, C)]
ABC.sort(reverse=True)
for i in range(k):
    print(ABC[i])
