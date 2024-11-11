import sys,functools,collections,bisect,math,heapq
input = sys.stdin.readline
#print = sys.stdout.write
sys.setrecursionlimit(200000)
mod = 10**9 + 7

def fun(a,b,s):
    x,y = 0,0
    for d in s:
        if d == 'L':
            if ((x-1)==a and y==b):
                continue
            x -= 1
        if d == 'R':
            if ((x+1)==a and y==b):
                continue
            x += 1
        if d == 'U':
            if (x== a and (y+1)==b):
                continue
            y += 1
        if d == 'D':
            if (x== a and (y-1)==b):
                continue 
            y -= 1
    return (x,y) == (0,0)     

t = int(input())
for _ in range(t):
    s = input().strip()
    
    points = set()
    x,y = 0,0
    for d in s:
        if d == 'L':
            x -= 1
            if (x== 0 and y==0):
                continue
            points.add((x,y))
        if d == 'R':
            x += 1
            if (x== 0 and y==0):
                continue
            points.add((x,y))
        if d == 'U':
            y += 1
            if (x== 0 and y==0):
                continue
            points.add((x,y))
        if d == 'D':
            y -= 1
            if (x== 0 and y==0):
                continue
            points.add((x,y))
            
    for a,b in points:
        if fun(a,b,s):
            print(a,b)
            break
    else:
        print('0 0')