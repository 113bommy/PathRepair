from __future__ import division, print_function
py2 = round(0.5)

if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange

import os, sys
from io import BytesIO, IOBase

# FastIO for PyPy2 and PyPy3 by Pajenegod
class FastI(object):
    def __init__(self, fd=0, buffersize=2**14):
        self.stream = stream = BytesIO(); self.bufendl = 0
        def read2buffer():
            curpos = stream.tell(); s = os.read(fd, buffersize + os.fstat(fd).st_size)
            stream.seek(0,2); stream.write(s); stream.seek(curpos); return s
        self.read2buffer = read2buffer
    def read(self):
        while self.read2buffer(): pass
        return self.stream.read() if self.stream.tell() else self.stream.getvalue()
    def readline(self):
        while self.bufendl == 0: s = self.read2buffer(); self.bufendl += s.count(b'\n') + (not s)
        self.bufendl -= 1; return self.stream.readline()
    def input(self): return self.readline().rstrip(b'\r\n')

class FastO(IOBase):
    def __init__(self, fd=1):
        stream = BytesIO()
        self.flush = lambda: os.write(fd, stream.getvalue()) + stream.truncate(0) + stream.seek(0)
        self.write = stream.write if py2 else lambda s: stream.write(s.encode())

sys.stdin, sys.stdout = FastI(), FastO()
input = sys.stdin.readline

big = 3E12

class segheap:
    def __init__(self,data):
        n = len(data)
        m = 1
        while m<n:m*=2
        self.n = n
        self.m = m

        self.data = [big]*(2*m)
        for i in range(n):
            self.data[i+m] = data[i]
        for i in reversed(range(m)):
            self.data[i] = min(self.data[2*i],self.data[2*i+1])

    def mini(self):
        i = 1
        while i<self.m:
            if self.data[i]==self.data[2*i]:
                i = 2*i
            else:
                i = 2*i+1
        i -= self.m
        self.setter(i,big)
        return i
    def setter(self,ind,val):
        ind += self.m
        if val<self.data[ind]:
            while ind>0 and self.data[ind]>val:
                self.data[ind] = val
                ind //= 2
        elif val>self.data[ind]:
            old_val = self.data[ind]
            self.data[ind] = val
            ind //= 2
            while ind>0 and self.data[ind]==old_val:
                self.data[ind] = min(self.data[2*ind],self.data[2*ind+1])
                ind //= 2



s = sys.stdin.read().replace(b'\r',b'')
inp = []
numb = 0
 
for i in range(len(s)):
    if s[i]>=48:
        numb = 10*numb + s[i]-48
    elif s[i]!=13:
        inp.append(numb)
        numb = 0
if s[-1]>=48:
    inp.append(numb)

ind = 0

n = inp[ind]
ind += 1
m = inp[ind]
ind += 1

coupl = [[] for _ in range(n)]
cost = [[] for _ in range(n)]
for _ in range(m):
    v = inp[ind+0]-1
    u = inp[ind+1]-1
    w = 1.0*inp[ind+2]
    ind += 3
    coupl[v].append(u)
    coupl[u].append(v)
    cost[u].append(w)
    cost[v].append(w)

best = [1.0*inp[ind+i] for i in range(n)]

Q = segheap(best)

while Q.data[1]!=big:
    c = Q.data[1]
    node = Q.mini()
    if best[node]!=c:
        continue
    for j in range(len(coupl[node])):
        nei = coupl[node][j]
        C = c+2*cost[node][j]
        if C<best[nei]:
            best[nei] = C
            Q.setter(nei,C)

for x in best:
    sys.stdout.write(str(int(x)))
    sys.stdout.write('\n')