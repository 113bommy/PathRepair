import os
import sys
from io import BytesIO, IOBase

# region fastio

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
#https://github.com/cheran-senthil/PyRival/blob/master/templates/template_py3.py


n,m,k=map(int,input().split())
y_axis=[list(map(int,input().split())) for i in range(n)]
x_axis=[list(map(int,input().split())) for i in range(n-1)]
if(k%2==1):
    for i in range(n):
        for j in range(m):
            print(-1,end=" ")
        print()
else:
    inf=10**9
    dp=[[[inf for z in range(k+1)]for y in range(m)]for x in range(n)]
    for i in range(n):
        for j in range(m):
            if(i>0):
                if(i<n-1):
                    dp[i][j][2]=min(dp[i][j][2],2*x_axis[i][j],2*x_axis[i-1][j])
                else:
                    dp[i][j][2]=min(dp[i][j][2],2*x_axis[i-1][j])
            else:
                dp[i][j][2]=min(dp[i][j][2],2*x_axis[i][j])
            if(j>0):
                if(j<m-1):
                    dp[i][j][2]=min(dp[i][j][2],2*y_axis[i][j],2*y_axis[i][j-1])
                else:
                    dp[i][j][2]=min(dp[i][j][2],2*y_axis[i][j-1])
            else:
                dp[i][j][2]=min(dp[i][j][2],2*y_axis[i][j])
    for z in range(4,k+1,2):
        for i in range(n):
            for j in range(m):
                if(i>0):
                    if(i<n-1):
                        dp[i][j][z]=min(dp[i][j][z],dp[i-1][j][z-2]+2*x_axis[i-1][j],dp[i+1][j][z-2]+2*x_axis[i][j])
                    else:
                        dp[i][j][z]=min(dp[i][j][z],dp[i-1][j][z-2]+2*x_axis[i-1][j])
                else:
                    dp[i][j][z]=min(dp[i][j][z],dp[i+1][j][z-2]+2*x_axis[i][j])
                if(j>0):
                    if(j<m-1):
                        dp[i][j][z]=min(dp[i][j][z],dp[i][j-1][z-2]+2*y_axis[i][j-1],dp[i][j+1][z-2]+2*y_axis[i][j])
                    else:
                        dp[i][j][z]=min(dp[i][j][z],dp[i][j-1][z-2]+2*y_axis[i][j-1])
                else:
                    dp[i][j][z]=min(dp[i][j][z],dp[i][j+1][z-2]+2*y_axis[i][j])
    for i in range(n):
        for j in range(m):
            if(dp[i][j][k]==inf):
                print(-1,end=" ")
            else:
                print(dp[i][j][k],end=" ")
        print()
                
                    
            
        
