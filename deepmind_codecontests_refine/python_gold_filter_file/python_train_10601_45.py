X, Y = map(int, input().split())
k = len(bin(Y//X)[2:])
print(k)