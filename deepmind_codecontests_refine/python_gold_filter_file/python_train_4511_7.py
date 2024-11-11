import sys
from math import factorial
input=sys.stdin.readline
INF=int(1e9)+7

def solve():
    n=int(input())
    if n%2==0:
        for i in range(n//2):
            print(2*i+2,end=' ')
            print(2*i+1,end=' ')
    else:
        print(3,1,2,end=' ')
        for i in range(1,n//2):
            print(2*i+3,end=' ')
            print(2*i+2,end=' ')
    print()






t=int(input())
while t:
    t-=1
    solve()
