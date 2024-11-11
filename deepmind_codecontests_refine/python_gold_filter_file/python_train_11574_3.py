#Code by Sounak, IIESTS
#------------------------------warmup----------------------------

import os
import sys
import math
from io import BytesIO, IOBase
from fractions import Fraction
import collections
from itertools import permutations
from collections import defaultdict


BUFSIZE = 8192
 
 
class FastIO(IOBase):
    newlines = 0
    
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
     
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
  
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

#-------------------game starts now-----------------------------------------------------
s=set(['a','e','i','o','u'])
n=int(input())
a=list()
e=list()
i=list()
o=list()
u=list()
for j in range (n):
    t=input()
    c=0
    en=''
    for k in t:
        if k in s:
            c+=1
            en=k
    if en=='a':
        a.append((c,en,t))
    elif en=='e':
        e.append((c,en,t))
    elif en=='i':
        i.append((c,en,t))
    elif en=='o':
        o.append((c,en,t))
    elif en=='u':
        u.append((c,en,t))
        
#print(a,e,i,o,u)
end=list()
start=list()
a.sort()
a.append((0,'a','a'))
j=1
while j<len(a):
    if a[j][0]==a[j-1][0]:
        end.append(a[j][2])
        end.append(a[j-1][2])
        j+=2
    else:
        start.append((a[j-1][0],a[j-1][2]))
        j+=1

e.sort()
e.append((0,'a','a'))
j=1
while j<len(e):
    if e[j][0]==e[j-1][0]:
        end.append(e[j][2])
        end.append(e[j-1][2])
        j+=2
    else:
        start.append((e[j-1][0],e[j-1][2]))
        j+=1
        
i.sort()
i.append((0,'a','a'))
j=1
while j<len(i):
    if i[j][0]==i[j-1][0]:
        end.append(i[j][2])
        end.append(i[j-1][2])
        j+=2
    else:
        start.append((i[j-1][0],i[j-1][2]))
        j+=1
        
o.sort()
o.append((0,'a','a'))
j=1
while j<len(o):
    if o[j][0]==o[j-1][0]:
        end.append(o[j][2])
        end.append(o[j-1][2])
        j+=2
    else:
        start.append((o[j-1][0],o[j-1][2]))
        j+=1

u.sort()
u.append((0,'a','a'))
j=1
while j<len(u):
    if u[j][0]==u[j-1][0]:
        end.append(u[j][2])
        end.append(u[j-1][2])
        j+=2
    else:
        start.append((u[j-1][0],u[j-1][2]))
        j+=1

#print(end)
#print(start)
l=len(end)
start.sort()
j=1
start.append((0,'a'))
while j<len(start):
    if start[j][0]==start[j-1][0]:
        end.append(start[j][1])
        end.append(start[j-1][1])
        j+=2
    else:
        j+=1
ct=len(end)-2
j=1
res=list()
while j<l:
    if ct>j:
        res.append((end[ct+1],end[j-1]))
        res.append((end[ct],end[j]))
        j+=2
        ct-=2
    else:
        break
print(len(res)//2)
for j in res:
    print(*j)