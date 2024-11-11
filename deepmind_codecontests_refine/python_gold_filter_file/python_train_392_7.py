N = int(input())
A = [int(input()) for _ in range(N)]
B = sorted(A)


for a in A:
    if a == B[-1]:
        print(B[-2])
    else:
        print(B[-1])