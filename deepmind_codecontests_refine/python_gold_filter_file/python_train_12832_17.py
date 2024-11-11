from collections import Counter
import math
import sys
from bisect import bisect,bisect_left,bisect_right
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def mod(): return 10**9+7
 
# Python3 programs to find two non-overlapping 
# pairs having equal Sum in an Array 

# Function to find two non-overlapping 
# with same Sum in an array 
def findPairs(arr, size): 

    # first create an empty Map 
    # key -> which is Sum of a pair of 
    # elements in the array 
    # value -> vector storing index of 
    # every pair having that Sum 
    Map = {} 

    # consider every pair (arr[i], arr[j]) 
    # and where (j > i) 
    for i in range(0, size - 1): 
        for j in range(i + 1, size): 
            
            # calculate Sum of current pair 
            Sum = arr[i] + arr[j] 

            # if Sum is already present in the Map 
            if Sum in Map: 

                # check every pair having equal Sum 
                for pair in Map[Sum]: 
                    m, n = pair 

                    # if pairs don't overlap, 
                    # print them and return 
                    if ((m != i and m != j) and(n != i and n != j)): 
                        
                        print("Pair First ({}, {})". 
                            format(arr[i], arr[j])) 
                        print("Pair Second ({}, {})". 
                            format(arr[m], arr[n])) 
                        return
                    
            # Insert current pair into the Map 
            if Sum not in Map: 
                Map[Sum] = [] 
            Map[Sum].append((i, j)) 
    
    # If no such pair found
    return []

for i in range(INT()): 
    n = INT()
    #s = input()
    #n,k,z = MAP()
    a = LIST()
    a.sort()
    if n == 1:
        print(0)
    else:
        x=a[0]+a[1]
        y=a[n-1]+a[n-2]
        visited = [0]*n
        ans=0
        for i in range(x,y+1):
            visited = [0]*n
            count = 0
     #       print(*visited)
            for j in range(n):
                val = i-a[j]
                if visited[j] == 0:
                    visited[j] = 1
                    for k in range(j+1,n):
                        if(val==a[k] and visited[k]==0):
                            count += 1
                            visited[k] = 1
                            break
            ans = max(ans,count)
        print(ans)


