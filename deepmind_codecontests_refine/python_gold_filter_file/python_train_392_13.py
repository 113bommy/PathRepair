N = int(input())
A = [int(input()) for _ in range(N)]
m1,m2 = sorted(A)[-2:]

for i in A:
    print(m1 if i==m2 else m2)