import sys
import os
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
import math
s = input()
n = int(input())
d = {}
reserve = ''
unique = 0
max_occur = 1
all_letters = ''
for x in s:
    if x in d:
        d[x] += 1
        if d[x] > max_occur:
            max_occur = d[x]
    else:
        d[x] = 1
        unique += 1
        all_letters += x
if unique > n:
    print(-1)
elif unique == n:
    print(max_occur)
    print(all_letters)
else:
    l = 1
    r = max_occur
    ans = max_occur
    check = 0
    final_str = all_letters
    check_str = ''
    while l<=r:
        mid = l + (r-l)//2
        check = 0
        check_str = ''
        reserve = ''
        for i in d.keys():
            if d[i] > mid:
                check += math.ceil(d[i]/mid)
                check_str += i*math.ceil(d[i]/mid)
                reserve += i*(d[i] - math.ceil(d[i]/mid))
            else:
                check += 1
                check_str += i
                reserve += i*(d[i]-1)
        if check <= n:
            final_str = '%s' % check_str
            if len(final_str) < n:
                final_str += reserve[:n-len(final_str)]
            if len(final_str) < n:
                final_str += 'a'*(n-len(final_str))
            ans = mid
            r = mid-1
        else:
            l = mid+1
    print(ans)
    print(final_str)