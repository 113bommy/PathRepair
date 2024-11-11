# by the authority of GOD   author: manhar singh sachdev #

import os,sys
from io import BytesIO,IOBase

def main():
    gr = [input().strip() for _ in range(3)]
    cnt1,cnt2 = sum(i.count('X') for i in gr),sum(i.count('0') for i in gr)
    if not (0 <= cnt1-cnt2 <= 1) or any(len(i) != 3 for i in gr):
        print('illegal')
        exit()
    dx,dy,se,who = [0,1,1,1],[1,1,0,-1],set(),-1
    for i in range(3):
        for j in range(3):
            for z in range(4):
                x,y,ar = i,j,[]
                while 0 <= x < 3 and 0 <= y < 3:
                    ar.append(gr[x][y])
                    x,y = x+dx[z],y+dy[z]
                if len(set(ar)) == 1 and ar[0] != '.' and len(ar) == 3:
                    se.add(ar[0])
                    who = ar[0]
    cnt = len(se)
    if cnt > 1 or (cnt == 1 and cnt1-cnt2 != (who == 'X')) or (cnt1+cnt2 == 9 and cnt1-cnt2 != 1):
        print('illegal')
    elif cnt == 1:
        print('the first player won' if who=='X' else 'the second player won')
    elif cnt1+cnt2 == 9:
        print('draw')
    else:
        print('second' if cnt1!=cnt2 else 'first')

# Fast IO Region
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
    def __init__(self,file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = os.read(self._fd,max(os.fstat(self._fd).st_size,BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0,2),self.buffer.write(b),self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd,max(os.fstat(self._fd).st_size,BUFSIZE))
            self.newlines = b.count(b"\n")+(not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0,2),self.buffer.write(b),self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
    def flush(self):
        if self.writable:
            os.write(self._fd,self.buffer.getvalue())
            self.buffer.truncate(0),self.buffer.seek(0)
class IOWrapper(IOBase):
    def __init__(self,file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s:self.buffer.write(s.encode("ascii"))
        self.read = lambda:self.buffer.read().decode("ascii")
        self.readline = lambda:self.buffer.readline().decode("ascii")
sys.stdin,sys.stdout = IOWrapper(sys.stdin),IOWrapper(sys.stdout)
input = lambda:sys.stdin.readline().rstrip("\r\n")
if __name__ == "__main__":
    main()