import atexit
import io
import sys
import math
from collections import defaultdict,Counter

# _INPUT_LINES = sys.stdin.read().splitlines()
# input = iter(_INPUT_LINES).__next__
# _OUTPUT_BUFFER = io.StringIO()
# sys.stdout = _OUTPUT_BUFFER

# @atexit.register
# def write():
#     sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

# sys.stdout=open("CP1/output.txt",'w')
# sys.stdin=open("CP1/input.txt",'r')

# m=pow(10,9)+7
t=int(input())
for i in range(t):
    n,x,y=map(int,input().split())
    s=x+y
    if x+y<=n:
        ma=s-1
    else:
        ma=n
    if x+y<=n:
        mi=1
    else:
        if s==2*n:
            mi=n
        else:
            mi=s-n+1
    print(mi,ma)