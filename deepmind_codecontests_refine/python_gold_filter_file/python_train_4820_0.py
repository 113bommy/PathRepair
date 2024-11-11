from collections import deque
from sys import stdin
 
input = stdin.readline
 

def solve():
    n = int(input())
    w = list(map(int, input().split()))
    nb = [0]*n
    for a in range(n-1):
        i,j = map(int, input().split())
        i-=1;j-=1
        nb[i]+=1
        nb[j]+=1
    vertex=[]
    for v in range(n):
        vertex.append((v, w[v]))
    vertex = sorted(vertex, key=lambda x: x[1],reverse=True)
 
    ans = [sum(w)]
    curr = 0
    while len(ans) < (n-1):
        v, we = vertex[curr]
        curr += 1
 
        while (nb[v]>1 and len(ans) < n-1):
            ans.append(ans[-1] + we)
            nb[v]-=1
    print(*ans)
 


t = int(input())
for s in range(0,t): solve()