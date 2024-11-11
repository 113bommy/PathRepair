##https://codeforces.com/problemset/problem/958/A1
from copy import deepcopy

def GenerateMap(n):
    positions = []
    for i in range(0,n):
        positions.append([])
    return positions

def Rotate(a, times):
    rotated = []
    for i in range(0,n):
        rotated.append([])
    counter = len(a)
    for i in rotated:
        counter-=1
        for j in a:
            i.append(j[counter])
    for i in range(0, times-1):
        counter = len(a)
        x = deepcopy(rotated)
        for j in rotated:
            j.clear()
            counter-=1
            for k in x:
                j.append(k[counter])
    return rotated

def Flip(a):
    flipped = []
    for i in reversed(a):
        flipped.append(i)
    return flipped

def CheckMaps(a,b):
    if a == b:
        return "Yes"
    elif Rotate(a, 1) == b:
        return "Yes"
    elif Rotate(a, 2) == b:
        return "Yes"
    elif Rotate(a, 3) == b:
        return "Yes"
    elif Flip(a) == b:
        return "Yes"
    elif Flip(Rotate(a, 1)) == b:
        return "Yes"
    elif Flip(Rotate(a, 2)) == b:
        return "Yes"
    elif Flip(Rotate(a, 3)) == b:
        return "Yes"
    else:
        return "No"
    

n = int(input())

a = GenerateMap(n)
b = GenerateMap(n)

for i in range(0,n):
    x = []
    x[:] = input()
    a[i] = x
for i in range(0,n):
    x = []
    x[:] = input()
    b[i] = x

print(CheckMaps(a,b))
