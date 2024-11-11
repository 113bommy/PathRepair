aI, aO, aT, aJ, aL, aS, aZ = map(int, input().split())

def calc(I, J, L) :        
    I -= I % 2
    J -= J % 2
    L -= L % 2
    return I + J + L
    
ret = aO + calc(aI, aJ, aL)
if aI >= 1 and aJ >= 1 and aL >= 1 :
    ret = max(ret, aO + calc(aI-1, aJ-1, aL-1) + 3)

print(ret)