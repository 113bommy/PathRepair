#from numpy import*
#from scipy import*
from collections import* #defaultdict Counter deque appendleft
#from fractions import gcd
#from functools import* #reduce
#from itertools import* #permutations("AB",repeat=2) combinations("AB",2) product("AB",2) groupby
#from operator import mul
#from bisect import* #bisect_left bisect_right
from heapq import* #heapify heappop heappushpop
#from math import factorial
#from copy import deepcopy
import sys
input=sys.stdin.readline  #危険！基本オフにしろ！
sys.setrecursionlimit(10**6)

def DIJKSTRA(point,d,n):
    cost      = {node:float("inf") for node in range(n)}
    Q         = []  #頂点のリスト
    cost[point]=0  #開始地点のコストをゼロとする（当たり前
    heappush(Q,(point,cost[point]))
    while Q:
        prefnd,tmpC=heappop(Q)
        if cost[prefnd]<tmpC:
            continue
        for node,c in d[prefnd]:
            altC=c+tmpC
            if cost[node]>altC:
                cost[node]=altC
                heappush(Q,(node,altC))
    return cost

def main():
    k=int(input())
    d=defaultdict(list)
    for i in range(k-1): #１加算をつなぐ
        d[i].append([i+1,1])
    d[k-1].append([0,1])
    for i in range(k):  #10倍をつなぐ
        d[i].append([(i*10)%k,0])
    #print(d)
    
    
    print(DIJKSTRA(1,d,k)[0]+1)

    
    
    
    
if __name__ == '__main__':
    main()