############ ---- Input Functions ---- ############
def readInt():
    return(int(input()))
def readList():
    return(list(map(int,input().rstrip().split())))
def readString():
    s = input()
    return s
def readInts():
    return(map(int,input().rstrip().split()))

def solve(n, arr):
    a = set([])
    for k in range(0, n):
        nxt = (k + arr[k % n])%n
        if nxt in a:
            return False
        a.add(nxt)
    return True


T = readInt()
for i in range(T):
    n = readInt()
    arr = list(readInts())
    r = solve(n, arr)
    if r:
        print("YES")
    else:
        print("NO")
