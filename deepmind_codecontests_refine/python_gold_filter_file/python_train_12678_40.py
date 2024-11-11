N, A, B = map(int, input().split())
r = N//(A+B)
print(r*A+min(A, N-r*(A+B)))