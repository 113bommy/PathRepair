T = int(input())
for t in range(T):
    n = int(input())
    A = [int(i) for i in input().split()]
    if sum(A)%n == 0:
        print(0)
    else:
        print(1)
