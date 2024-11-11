def getInts():
    return [int(s) for s in input().split()]

def getInt():
    return int(input())

def getStrs():
    return [s for s in input().split()]

def getStr():
    return input()

def listStr():
    return list(input())

def solve():
    S = getStr()
    lang = list('HQ9')
    for s in S:
        if s in lang:
            return "YES"
    return "NO"
    
ans = solve()
print(ans)