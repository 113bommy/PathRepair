t = int(input())

EPS = 1e-9

for i in range(t):
    n = int(input())
    print(int(n ** (1 / 2) + EPS) + int(n ** (1 / 3) + EPS) - int(n ** (1 / 6) + EPS))