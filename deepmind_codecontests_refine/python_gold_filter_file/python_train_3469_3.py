import sys
from math import ceil
input = lambda:sys.stdin.readline().strip()
scale = 1e7
def solve(c,m,p,v):
    ans = p/scale
    if c>0:
        if c>v:
            if m>0:
                ans+=(c/scale)*(1+solve(c-v,m+v//2,p+v//2,v))
            else:
                ans+=(c/scale)*(1+solve(c-v,0,p+v,v))
        else:
            if m>0:
                ans+=(c/scale)*(1+solve(0,m+c//2,p+c//2,v))
            else:
                ans+=(c/scale)*(1+solve(0,0,p+c,v))
    if m>0:
        if m>v:
            if c>0:
                ans+=(m/scale)*(1+solve(c+v//2,m-v,p+v//2,v))
            else:
                ans+=(m/scale)*(1+solve(0,m-v,p+v,v))
        else:
            if c>0:
                ans+=(m/scale)*(1+solve(c+m//2,0,p+m//2,v))
            else:
                ans+=(m/scale)*(1+solve(0,0,p+m,v))
    return ans
t = int(input())
while t:
    t-=1
    c,m,p,v = map(float,input().split())
    c,m,p,v = ceil(c*scale),ceil(m*scale),ceil(p*scale),ceil(v*scale)
    print(solve(c,m,p,v))