A, B = map(int, input().rstrip().split())
print(max(A+B, A-B, A*B))