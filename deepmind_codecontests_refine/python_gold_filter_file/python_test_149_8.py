import os
import sys
from io import BytesIO, IOBase
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = 'x' in file.mode or 'r' not in file.mode
        self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b'\n') + (not b)
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
        self.write = lambda s: self.buffer.write(s.encode('ascii'))
        self.read = lambda: self.buffer.read().decode('ascii')
        self.readline = lambda: self.buffer.readline().decode('ascii')
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')

for _ in range(int(input())):
    n, k, x = map(int, input().split())
    s = input()
    arr = []
    for i in s:
        if i == 'a':
            arr.append('a')
        else:
            if len(arr) == 0:
                arr.append(1)
            elif arr[-1] == 'a':
                arr.append(1)
            else:
                arr[-1] += 1
    groups = [i for i in arr if i != 'a']
    # print("groups", grosups)
    val = [0 for i in groups]

    for i in range(len(groups)):
        current_strings = k * groups[i] + 1
        ahead_strings = 1
        for j in range(i + 1, len(groups)):
            ahead_strings *= k * groups[j] + 1
            if ahead_strings >= x:
                break
        val[i] = (x - 1) // ahead_strings
        x -= ahead_strings * val[i]
    # print("val", val)

    i, j = 0, 0
    ans = []
    while i < len(arr):
        if arr[i] == 'a':
            ans.append('a')
        else:
            ans.append('b' * val[j])
            j += 1
        i += 1
    print(''.join(ans))