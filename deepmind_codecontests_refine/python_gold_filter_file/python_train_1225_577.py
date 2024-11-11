N, K = map(int, input().split())
A = sorted(map(int, input().split()))
print(sum(A[:K]))