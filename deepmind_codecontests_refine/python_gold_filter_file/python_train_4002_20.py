from functools import reduce
from operator import *
from math import *
from sys import *
from string import *
setrecursionlimit(10**7)
dX= [ 0, 0, 1,-1, 1,-1, 1,-1]
dY= [ 1,-1, 0, 0, 1,-1,-1, 1]
RI=lambda: list(map(int,input().split()))
RS=lambda: input().rstrip().split()
#################################################
s=RS()[0]
if len(s)>=5 and any(i in ascii_lowercase for i in s) and any(i in ascii_uppercase for i in s) and any(i in digits for i in s):
    print("Correct")
else:
    print("Too weak")

