def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) ]))
def invr():
    return(map(int,input().split()))

k = inp()
for i in range(k):
    n = inp()
    denom = int((n+1)/2)
    print(denom)