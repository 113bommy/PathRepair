X, Y, Z, K = map(int, input().split())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]
C = [int(i) for i in input().split()]

AB = sorted([a + b for a in A for b in B], reverse=True)[:K]
ABC = sorted([ab + c for ab in AB for c in C], reverse=True)[:K]
for a in ABC:
    print(a)
