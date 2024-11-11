import math,sys
#from itertools import permutations, combinations;import heapq,random;
from collections import defaultdict,deque
import bisect as bi
def yes():print('YES')
def no():print('NO')
#sys.stdin=open('input.txt','r');sys.stdout=open('output.txt','w');
def I():return (int(sys.stdin.readline()))
def In():return(map(int,sys.stdin.readline().split()))
def Sn():return sys.stdin.readline().strip()
#sys.setrecursionlimit(1500)
def dict(a):
    d={} 
    for x in a:
        if d.get(x,-1)!=-1:
            d[x]+=1
        else:
            d[x]=1
    return d
def find_gt(a, x):
    'Find leftmost value greater than x'
    i = bi.bisect_left(a, x)
    if i != len(a):
        return i
    else:            
        return -1
def main():
    try:
        n=I()
        s=Sn()
        d=set(['a','e','i','o','u','y'])
        last=s[0]
        ans=[]
        for i in range(n):
            if len(ans) and ans[-1] in d and s[i] in d:
                continue
            else:
                ans.append(s[i])
        print(''.join(ans))



    except:
        pass
        
M = 998244353
P = 1000000007
 
if __name__ == '__main__':
    # for _ in range(I()):main()
    for _ in range(1):main()
#End#

#        ******************* All The Best *******************   #