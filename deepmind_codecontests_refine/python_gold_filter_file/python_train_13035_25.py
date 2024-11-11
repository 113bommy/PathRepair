import collections

local = False
if local:
    file = open("A.txt", "r")

def readInput():
    if local:
        return file.readline()
    else:
        return input()

def stairs(n, s, k, closed):
    sclosed = set(closed)
    minup = n+1
    mindown = n+1
    for i in range(s, n+1):
        if i not in sclosed:
            minup = i-s
            break

    for i in range(s,0,-1):
        if i not in sclosed:
            mindown = s-i
            break
    
    return min(minup, mindown)



t = int(readInput())
for i in range(t):
    nsk = readInput().split()
    n, s, k = int(nsk[0]), int(nsk[1]), int(nsk[2])
    closed = [int(x) for x in readInput().split()]
    
    print(stairs(n, s, k, closed))