from math import *
from sys import *
from collections import defaultdict
import os, sys
from io import IOBase, BytesIO
M=10**9+7
def pow(a,b):
    res=1
    while b>0:
        if b&1:
            res*=a
        a*=a
        b>>=1
    return res
def powmod(a,b,m):
    res=1
    while b>0:
        if b&1:
            res=((res*a)%m)
        a*=a
        b>>=1
    return res
def inv(a,m):
    return powmod(a,m-2,m)

def factor(n):
    potentional_p = 3
    itog_list = {}
    if n % 2 == 0:
        itog_list[2] = 0
    while n % 2 == 0:
        n = n // 2
        itog_list[2] += 1
    while n - 1:
        if potentional_p > (n**0.5):
            if n in itog_list:
                itog_list[n] += 1
            else:
                itog_list[n] = 1
            return itog_list
        while n % potentional_p == 0:
            n = n // potentional_p
            if potentional_p in itog_list:
                itog_list[potentional_p] += 1
            else:
                itog_list[potentional_p] = 1
        potentional_p += 2
    return itog_list



def main():
    t=int(input())
    s=input()
    r=s.count('R')
    g=s.count('G')
    b=s.count('B')
    if r>0 and g>0 and b>0:
        print('BGR')
    elif r==0 and b>0 and g>0:
        if b==1 and g==1:
            print('R')
        elif b==1 and g>=2:
            print('BR')
        elif b>=2 and g==1:
            print('GR')
        else:
            print('BGR')
    elif b==0 and r>0 and g>0:
        if r==1 and g==1:
            print('B')
        elif r==1 and g>=2:
            print('BR')
        elif r>=2 and g==1:
            print('BG')
        else:
            print('BGR')
    elif g==0 and r>0 and b>0:
        if r==1 and b==1:
            print('G')
        elif r==1 and b>=2:
            print('GR')
        elif r>=2 and b==1:
            print('BG')
        else:
            print('BGR')
    elif b>0:
        print('B')
    elif r>0:
        print('R')
    elif g>0:
        print('G')
    
        









BUFSIZE = 8192
class FastIO(BytesIO):
    newlines = 0
 
    def __init__(self, file):
        self._file = file
        self._fd = file.fileno()
        self.writable = "x" in file.mode or "w" in file.mode
        self.write = super(FastIO, self).write if self.writable else None
 
    def _fill(self):
        s = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
        self.seek((self.tell(), self.seek(0,2), super(FastIO, self).write(s))[0])
        return s
 
    def read(self):
        while self._fill(): pass
        return super(FastIO,self).read()
 
    def readline(self):
        while self.newlines == 0:
            s = self._fill(); self.newlines = s.count(b"\n") + (not s)
        self.newlines -= 1
        return super(FastIO, self).readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.getvalue())
            self.truncate(0), self.seek(0)
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s:self.buffer.write(s.encode('ascii'))
        self.read = lambda:self.buffer.read().decode('ascii')
        self.readline = lambda:self.buffer.readline().decode('ascii')
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')
 
if __name__ == '__main__':
    main()
#threading.Thread(target=main).start()






