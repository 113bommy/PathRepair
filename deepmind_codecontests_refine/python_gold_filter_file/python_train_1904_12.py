import sys
import math
input = sys.stdin.readline

def solve():
    n,m=map(int,input().split())
    L=list(map(int,input().split()))
    ans = 0
    for i in range(1,n+1):
        for j in range(i,n+1):
            ans+=L[j-1]/j
    if round(ans)==m:
        print('YES')
    else:
        print('NO')


if __name__=="__main__":
    for _ in range(int(input())):
        solve()
