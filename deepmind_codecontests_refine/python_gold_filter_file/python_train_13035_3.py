import math,sys
from collections import Counter, defaultdict, deque
from sys import stdin, stdout
input = stdin.readline
lili=lambda:list(map(int,sys.stdin.readlines()))
li = lambda:list(map(int,input().split()))
#for deque append(),pop(),appendleft(),popleft(),count()
I=lambda:int(input())
S=lambda:input().strip()
mod = 1000000007

for i in range(I()):
    n,s,k=li()
    a=li()
    d=Counter(a)
    p=s 
    q=s
    while(True):
        if(p not in d):
            print(p-s)
            break
        elif(q not in d):
            print(s-q)
            break
        else:
            p=min(p+1,n)
            q=max(1,q-1)
    
    