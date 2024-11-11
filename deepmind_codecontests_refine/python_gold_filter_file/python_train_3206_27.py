A, B, K=map(int, input().split())

A, B=A-min(A, K), max(0, B+min(0, A-K))

print(A, B)