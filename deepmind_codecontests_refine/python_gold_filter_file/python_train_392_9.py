N = int(input())
A = [int(input()) for i in range(N)]

a = max(A)
b = sorted(A)[-2]
for i in A:
    print(b if i == a else a)
