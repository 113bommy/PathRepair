# cook your dish here
MOD =  1000000007
#import time
#import heapq
#import math
#import string
#import bisect


def solve(n,k):
    if n==2:
        ans = 2*k-1
    else:
        if k%(n-1)==0:
            ans = n*(k//(n-1))-1
        else:
            ans = n*(k//(n-1)) + k%(n-1)
    print(ans)
     
            
for i in range(int(input())):
    #x,y,l,r= map(int,input().split())
    n,k= map(int,input().split())
    #n = int(input())
    #a = list(map(int,input().split()))
    #b = list(map(int,input().split()))
    #l,r= map(int,input().split())
    #n = int(input())
    #s = input()
    #sa = list(map(str,input().split()))
    #b = list(map(int,input().split()))
    #st = time.process_time()
    solve(n,k)
    #print(s)
    #pt = solve(s)
    #print(pt)
    #print("yes" if pt==1 else "no")
    #print("Linear : ",time.process_time() - st)