import math
wej = [int(i) for i in input().split()]
a = wej[0]
b = wej[1]
n = wej[2]
zliczenie = 0

for i in range(-1000, 1001):
    if a*i**n == b:
        print(i)
        zliczenie += 1
        break

if zliczenie == 0:
    print("No solution")