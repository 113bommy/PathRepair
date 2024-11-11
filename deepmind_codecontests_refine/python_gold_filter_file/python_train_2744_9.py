from sys import stdin, stdout
import math,sys
#sys.stdout = open('output.txt', 'w')
#sys.stdin = open('input.txt','r')
from itertools import permutations, combinations
from collections import defaultdict
import bisect
import heapq as hq
 
 
 
def main():
    try:
        x,y=-1,-1
        ans=1
        temp=1
        for i in range(int(input())):
            a,b=map(int,input().split())
            if a==x and b==y:
                ans+=1
            else:
                x,y=a,b
                temp=max(ans,temp)
                ans=1
                
        print(max(ans,temp))
    except:
        pass
 
 
P = 1000000007
def search(l,x):
    a,b=0,len(l)-1
    while (a<=b):
        k=(a+b)//2
        if l[k]==x:
            return k
        elif l[k]<x:
            a=k+1
        else:
            b=k-1
 
if __name__ == '__main__':
    main()