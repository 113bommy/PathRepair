import atexit
import io
import sys

# _INPUT_LINES = sys.stdin.read().splitlines()
# input = iter(_INPUT_LINES).__next__
# _OUTPUT_BUFFER = io.StringIO()
# sys.stdout = _OUTPUT_BUFFER
#
#
# @atexit.register
# def write():
#     sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

from collections import Counter

i,s=input,[0]
i()
for n in map(int,i().split()):
    s+=[s[-1]+n]
# print(s)
for _ in [0]*int(i()):
    x,y=map(int,i().split())
    print((s[y]-s[x-1])//10)