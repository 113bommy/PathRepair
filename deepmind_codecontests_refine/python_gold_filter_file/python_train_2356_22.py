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
n=inp()
l=inlt()
c=0
for i in range(1,n-1):
    if (l[i]>l[i-1] and l[i]>l[i+1]) or (l[i]<l[i-1] and l[i]<l[i+1]):
        c=c+1
print(c)
