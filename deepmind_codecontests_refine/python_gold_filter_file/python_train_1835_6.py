from sys import stdin,stderr,maxsize
mod = int(1e9)+7
def I(): return int(stdin.readline())
def lint(): return [int(x) for x in stdin.readline().split()]
def S(): return input().strip()
def grid(r, c): return [lint() for i in range(r)]
def debug(*args, c=6): print('\033[3{}m'.format(c), *args, '\033[0m', file=stderr)
from collections import Counter,defaultdict
from itertools import permutations

def bark():
    n = I()
    s =S();ma = -1
    #if n==1 and s[0].islower():return 1
    arr =[]
    for i in range(n):
        for j in range(i,n):
            p =[z for z in  s[i:j+1] if z.isupper()]
            #print(p,s[i:j+1])
            if len(p)==0:
                a = len(set(s[i:j+1]))
                if a > ma:
                    ma = a
    if ma==-1 : return 0
    else:return ma
if __name__ == '__main__':
    print(bark())

