A = []
for i in range(3):
    A.append(list(input().split()))
N = int(input())
B = []
for i in range(N):
    B.append(input())
B=set(B)
if set(A[0]) <= B or set(A[1]) <= B or set(A[2]) <= B or {A[0][0], A[1][0], A[2][0]} <= B or\
{A[0][1], A[1][1], A[2][1]} <= B or {A[0][2], A[1][2], A[2][2]} <= B \
or {A[0][0], A[1][1], A[2][2]} <= B or {A[0][2], A[1][1], A[2][0]} <= B:
    print("Yes")
else:
    print("No")