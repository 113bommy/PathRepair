import os
import sys

def log(*args, **kwargs):
    if os.environ.get('CODEFR'):
        print(*args, **kwargs)


n, m = tuple(map(int,input().split()))
r = min(n+1, m+1)
print(r)
for i in range(r):
    print(r-1-i, i)
