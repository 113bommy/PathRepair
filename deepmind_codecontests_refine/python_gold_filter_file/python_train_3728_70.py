X, Y, Z, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

AB = sorted([a + b for a in A for b in B])[-1:-K-1:-1]
ABC = sorted([ab + c for ab in AB for c in C])[-1:-K-1:-1]
print('\n'.join(map(str, ABC)))
