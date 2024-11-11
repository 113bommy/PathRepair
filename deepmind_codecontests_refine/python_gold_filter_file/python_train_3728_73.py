import itertools


X, Y, Z, K = list(map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

AB = [a + b for (a, b) in list(itertools.product(A, B))]
AB.sort(reverse=True)
ans = [ab + c for (ab, c) in list(itertools.product(AB[:min(3000, X*Y*Z)], C))]
ans.sort(reverse=True)
for i in range(K):
    print(ans[i])
