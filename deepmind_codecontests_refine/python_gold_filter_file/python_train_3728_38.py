import itertools


x, y, z, k = list(map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
AB = [a + b for (a, b) in list(itertools.product(A, B))]
AB.sort(reverse=True)
ABC = [ab + c for (ab, c) in list(itertools.product(AB[:k], C))]
ABC.sort(reverse=True)

for i in range(k):
    print(ABC[i])
