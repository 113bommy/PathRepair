from __future__ import division, print_function
py2 = round(0.5)

if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange

import os, sys
from io import BytesIO, IOBase

# FastIO for PyPy2 and PyPy3 by Pajenegod,
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
    def readnumbers(self, n,zero=0):
        conv = ord if py2 else lambda x:x
        
        A = []; numb = zero; sign = 1
        
        curpos = self.stream.tell()
        self.stream.seek(0,2)
        buffsize = self.stream.tell()
        self.stream.seek(curpos)
        
        while len(A)<n:
            if curpos>=buffsize:
                self.read2buffer()
                self.stream.seek(0,2)
                buffsize = self.stream.tell()
                self.stream.seek(curpos)
                if curpos==buffsize: break
            s = self.stream.read(min(256,buffsize-curpos))
            i = 0
            while i<len(s) and len(A)!=n:
                if s[i] >= b'0'[0]: numb = 10 * numb + (conv(s[i]) - 48)
                elif s[i] != b'\r'[0]: 
                    if s[i] == b'-'[0]: sign = -1
                    else: A.append(sign*numb); numb = zero; sign = 1
                i += 1
            curpos += i
        if curpos == buffsize and len(A)<n: A.append(sign*numb)
        assert(len(A)==n)
        self.stream.seek(curpos)
        return A

class FastO(IOBase):
    def __init__(self, fd=1):
        stream = BytesIO()
        self.flush = lambda: os.write(1, stream.getvalue()) and not stream.truncate(0) and stream.seek(0)
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

n, m = [int(x) for x in sys.stdin.readline().split()]

inp = sys.stdin.readnumbers(3*m, 0.0)

coupl = [[] for _ in range(n)]
cost = [[] for _ in range(n)]
for _ in range(m):
    v = int(inp[_*3+0]-1)
    u = int(inp[_*3+1]-1)
    w = inp[_*3+2]
    coupl[v].append(u)
    coupl[u].append(v)
    cost[u].append(w)
    cost[v].append(w)

inp = sys.stdin.readnumbers(n, 0.0)

best = [inp[i] for i in range(n)]

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
    sys.stdout.write(' ')