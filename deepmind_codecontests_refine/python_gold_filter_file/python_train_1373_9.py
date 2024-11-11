# ------------------- fast io --------------------
import os
import sys
from io import BytesIO, IOBase
 
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
 
# ------------------- fast io --------------------
x1,y1,x2,y2=map(int,input().split())
x3,y3,x4,y4=map(int,input().split())
x5,y5,x6,y6=map(int,input().split())
if x3<=x1 and y3<=y1 and x2<=x4 and y2<=y4:
    print("NO")
elif x5<=x1 and y5<=y1 and x2<=x6 and y2<=y6:
    print("NO")
else:
    if y3<=y1:
        if x3<=x1 and x2<=x4:
            y1=max(y1,y4)
    elif y2<=y4:
        if x3<=x1 and x2<=x4:
            y2=min(y2,y3)
    if x3<=x1:
        if y3<=y1 and y2<=y4:
            x1=max(x1,x4)
    elif x2<=x4:
        if y3<=y1 and y2<=y4:
            x2=min(x2,x3)
    #then we'll patch it up, see if last rectangle covers it
    if x5<=x1 and y5<=y1 and x2<=x6 and y2<=y6:
        print("NO")
    else:
        print("YES")