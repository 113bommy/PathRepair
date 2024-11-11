import os.path
import sys
from math import *
from math import floor, gcd, fabs, factorial, fmod, sqrt, inf, log
if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

def inp(): return sys.stdin.readline().strip()

n,a,b=map(int,inp().split())
a-=1
b-=1
match=0
while a!=b:
    a//=2
    b//=2
    match+=1
if (1<<match)==n:
    print("Final!")
else: print(match)