X, Y = map(int, input().split())

P = [300000, 200000, 100000, 0]

if X == 1 and Y == 1:
    print(1000000)
else:
    print(P[min(3, X - 1)] + P[min(3, Y - 1)])
