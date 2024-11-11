N, K = map(int, input().split())
A = sorted(list(map(int, input().split())))
print(sum(A[:K]))