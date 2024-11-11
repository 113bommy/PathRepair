    #from _typeshed import SupportsKeysAndGetItem
import sys
from collections import deque
import heapq
import bisect
import copy
# sys.stdin=open("input.txt","r");
# sys.stdout=open("output.txt","w")
####### GLOBAL ###############
MOD=1000000007
NO=lambda:print("NO")
YES=lambda:print("YES")
_1=lambda:print(-1)
ari=lambda:[int(_) for _ in input().split()]
cin=lambda:int(input())
cis=lambda:input()
show=lambda x: print(x)
fast= lambda:sys.stdin.readline()

########### END #########
######
test_case=1
test_case=int(input())
######
sys.setrecursionlimit(10**6)
    
def ans():
    n=cin()
    arr=ari()
    count=0
    intail=1
    # arr.sort()
    for i  in range(n):
        if arr[i]>intail:
            dist=abs(intail-arr[i])
            count+=dist
            intail+=dist+1
        else:
            intail+=1
    print(count)
    return

for _ in range(test_case):
    ans()
    