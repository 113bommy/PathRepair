n = int(input())
r = 0
cubes = 0
while n > 0:
    r+=1
    cubes += r
    n -= cubes
    if n < cubes + r + 1:
        break

print(r)
