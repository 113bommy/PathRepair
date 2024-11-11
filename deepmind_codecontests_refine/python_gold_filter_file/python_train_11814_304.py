x, y = map(int, input().split())

numDominos = 0

if (x % 2 == 0) | (y % 2 == 0):
    numDominos = x * y / 2
else:
    numDominos += ((x-1)/2) * y
    numDominos += (y-1)/2

print(int(numDominos))