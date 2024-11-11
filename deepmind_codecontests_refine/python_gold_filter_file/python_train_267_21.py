from sys import maxsize, stdout, stdin,stderr
mod = int(1e9 + 7)
import re #can use multiple splits
tup = lambda : map(int,stdin.readline().split())
I = lambda :int(stdin.readline())
lint=lambda : [int(x) for x in stdin.readline().split()]
S = lambda :stdin.readline().replace('\n','').strip()
def grid(r, c): return [lint() for i in range(r)]
def debug(*args, c=6): print('\033[3{}m'.format(c), *args, '\033[0m', file=stderr)
from  math import  log2,sqrt
from collections import defaultdict
c , v0,v1,a,l = tup()
cnt ,x,p =1,v0,0
c-=v0
while c > 0:
    cnt+=1
    v0 = min(v1, v0+a)
    c-=(v0-l)
print(cnt)














