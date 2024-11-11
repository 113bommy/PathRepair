import os,sys,math 
from io import BytesIO, IOBase
from collections import defaultdict,deque,OrderedDict
import bisect as bi
def yes():print('YES')
def no():print('NO')
def I():return (int(input()))
def In():return(map(int,input().split()))
def ln():return list(map(int,input().split()))
def Sn():return input().strip()
BUFSIZE = 8192
#complete the main function with number of test cases to complete greater than x
def find_gt(a, x):
    i = bi.bisect_left(a, x)
    if i != len(a):
        return i
    else:            
        return len(a)


def check(a,l):
    n1=len(l)
    for j in range(n1):
        cnt=0
        for i in range(m):
            if a[i]!=l[j][i]:
                cnt+=1
        if cnt>1:
            return False
    return True

def solve():
    global n,m
    n,m=In()
    l=set()
    for i in range(n):
        l.add(Sn())
    l=list(l)
    n1=len(l)
    pos=[set() for i in range(m)]
    for i in range(m):
        for j in range(n1):
            pos[i].add(l[j][i])
        # if len(pos[i])>2 and i!=0:
        #     print(-1)
        #     return
    ans=[[]]
    for i in range(m):
        temp=[]
        for y in pos[i]:
            for x in ans:
                t=x.copy()
                t.append(y)
                temp.append(t.copy())
        ans.clear()
        ans=temp.copy()
        if len(ans)>10000:
            print(-1)
            return


    ok=False
    for x in ans:
        if check(x,l):
            print(''.join(x))
            return
    print(-1)
    pass




def main():
    T=I()
    for i in range(T):
        solve()
        
M = 998244353
P = 1000000007
 




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


def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()


if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

input = lambda: sys.stdin.readline().rstrip("\r\n")

# endregion

if __name__ == '__main__':
    main()