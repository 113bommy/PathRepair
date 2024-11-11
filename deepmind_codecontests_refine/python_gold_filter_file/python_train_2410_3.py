from collections import defaultdict
import atexit
import io
import sys
_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER
@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())
    

n = int(input())
a = defaultdict(list)
parent = [0]*(n+1)
res = [0]*(n+1)
b = []
for i in range(1,n+1):
    p,r = map(int,input().split())
    parent[i] = p
    res[i] = r
    a[p].append(i)

for i in range(1,n+1):
    if res[i]==1:
        work = True
        for j in a[i]:
            if res[j]==0:
                work=False
                break
        if work:
            b.append(i)
b.sort()
if len(b)!=0:
    print(*b)
else:
    print("-1")

    


        