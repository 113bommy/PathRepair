import sys
from math import gcd,log2
def get_array(): return list(map(int, sys.stdin.readline().split()))
def get_ints(): return map(int, sys.stdin.readline().split())
def input(): return sys.stdin.readline().strip('\n')

out = [-1, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401]
l = [ (1<<i)-1 for i in range(26) ]

for _ in range(int(input())):
    n = int(input())
    if n in l:
        c = 0
        for i in l:
            if i == n:
                print(out[c-1])
                break
            c+=1
    else:
        k = int(log2(n)) + 1
        print( (1<<k) - 1) 
