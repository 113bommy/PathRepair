import os
import sys
from io import BytesIO, IOBase
BUFSIZE = 8192
inf=float('inf')
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
get = lambda: sys.stdin.readline().rstrip("\r\n")
#################################################################################
#################################################################################
for _ in range(int(get())):
    n=int(get())
    l=get()
    ans=10**9
    for c in range(26):
        i=0
        j=n-1
        f=0
        a=0
        while i<j:
            if l[i]==l[j]:
                i+=1
                j-=1
            else:
                if l[i]==chr(97+c):
                    i+=1
                    a+=1
                elif l[j]==chr(97+c):
                    j-=1
                    a+=1
                else:
                    f=1
                    break
        if f==0:
            ans=min(ans,a)
    if ans==10**9:
        print(-1)
    else:
        print(ans)





