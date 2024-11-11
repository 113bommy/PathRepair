N = int(input())
T = list(map(int, input().split()))
M = int(input())
for i in range(M):
    P, X = map(int, input().split())
    print(sum(T) - T[P-1] + X)
