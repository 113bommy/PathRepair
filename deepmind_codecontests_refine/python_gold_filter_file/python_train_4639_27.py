import math

x, y = [int(x) for x in input().split()]
n = int(input())
L = []
for i in range(n):
    X, Y, V = [int(x) for x in input().split()]
    L.append(math.sqrt((X-x)**2+(Y-y)**2)/V)
print(min(L))