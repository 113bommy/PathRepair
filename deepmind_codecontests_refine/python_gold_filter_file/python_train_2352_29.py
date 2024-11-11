import sys
input = sys.stdin.readline
import math
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

n,m,k=invr()
li=inlt()
if m==1:
    for i in range(n):
        if li[i]!=0 and li[i]<=k:
            print(i*10)
            break
elif m==n:
    for i in range(1,n+1):
        if li[-i]!=0 and li[-i]<=k:
            print((i-1)*10)
            break
else:
    ans1=10000
    ans2=10000
    pos=n-m+1
    for i in range(m,n):
        if li[i]!=0 and li[i]<=k:
            ans1=((i+1-m)*10)
            break
    for i in range(pos+1,n+1):
        if li[-i]!=0 and li[-i]<=k:
            ans2=((i-pos)*10)
            break
    #print(str(ans1)+ " " + str(ans2))
    print(min(ans1,ans2))
