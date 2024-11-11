import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
# --------------------------------------------------
num = inp()
for x in range(num):
    s = input().strip()
    if len(s)>10:
        count = len(s)-2
        print(s[0] + str(count) + s[-1])
    else:
        print(s)
