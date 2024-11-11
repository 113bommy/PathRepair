import sys
input = sys.stdin.readline
 
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s)]))
def invr():
    return(map(int,input().split()))
 
t = inp()
for testcase in range(t):
    c = True
    n = inp()
    s = inlt()
    i = 0
    j = 1
    it = s[0]+s[1]
    for k in range(2, n):
        if s[k] >= it:
            print(1, 2, k+1)
            c = False
            break
    if not c:
        continue
    print(-1)