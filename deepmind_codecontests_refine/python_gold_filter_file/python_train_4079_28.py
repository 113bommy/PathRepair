from heapq import heappush, heappop
from collections import deque, Counter, defaultdict
import itertools
import sys
#import bisect
sys.setrecursionlimit(10**6)
def MI():
    return map(int,input().split())
def I():
    return int(input())
def LI():
    return [int(i) for i in input().split()]
YN=['YES','NO']
input=sys.stdin.readline
 
q=I()
for _ in range(q):
    ans=0
    n=I()

    xmin,ymin=-10**5,-10**5
    xmax,ymax=10**5,10**5
    xf,yf=True,True
    for i in range(n):
        x,y,*a=LI()
        #x+=10**5
        #y+=10**5
        if a[0]*a[2]==1:
            pass
        elif a[0]==1:
            xmax=min(xmax,x)
        elif a[2]==1:
            xmin=max(xmin,x)
        else:
            if xmin<=x<=xmax:
                pass
            else:
                xf=False
            xmin=x
            xmax=x
            
        if a[1]*a[3]==1:
            pass
        elif a[3]==1:
            ymax=min(ymax,y)
        elif a[1]==1:
            ymin=max(ymin,y)
        else:
            if ymin<=y<=ymax:
                pass
            else:
                yf=False
            ymin=y
            ymax=y

    if xmax>=xmin and ymax>=ymin and xf and yf:
        print(1,xmin,ymin)#,xmax,ymax)
    else:
        print(0)
    #print(t,n,ax,ay,a,max(xp),max(yp),xp[10**5-5:10**5+5],yp[10**5-5:10**5+5])