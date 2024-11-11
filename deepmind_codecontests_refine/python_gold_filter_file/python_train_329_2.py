import sys
import collections
from io import BytesIO, StringIO

# input = BytesIO().readline
input = sys.stdin.readline
def rints():
    return map(int, input().strip().split())
def rint():
    return int(input().strip())

n, p, w, d = rints()
for y in range(10**5+10):
    if (p-d*y)%w == 0:
        x = (p-d*y)//w
        if x >= 0 and x + y <= n:
            print(x, " ", y, " ", n-y-x)
            exit(0)

print(-1)

    



