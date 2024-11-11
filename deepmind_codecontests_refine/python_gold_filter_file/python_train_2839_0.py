import sys


class Fastio:
    def __init__(self):
        self.ibuf = bytearray()
        self.obuf = bytearray()
        self.pil = 0
        self.pir = 0
        self.sz = 1 << 17

    def load(self):
        self.ibuf = self.ibuf[self.pil:]
        self.ibuf.extend(sys.stdin.buffer.read(self.sz))
        self.pil = 0
        self.pir = len(self.ibuf)

    def flush(self):
        sys.stdout.buffer.write(self.obuf)
        self.obuf = bytearray()

    def fastin(self):
        if self.pir - self.pil < 32:
            self.load()
        minus = 0
        x = 0
        while self.ibuf[self.pil] < ord('-'):
            self.pil += 1
        if self.ibuf[self.pil] == ord('-'):
            minus = 1
            self.pil += 1
        while self.ibuf[self.pil] >= ord('0'):
            x = x * 10 + (self.ibuf[self.pil] & 15)
            self.pil += 1
        if minus:
            x = -x
        return x


'''
    def __del__(self):
        self.flush()

    def fastout(self, x):
        if x < 0:
            obuf.join(b'-')
            x = -x
'''

fastio = Fastio()
rd = fastio.fastin
# wtn = fastio.fastout

N = rd()
a = [0] * N
for i in range(N):
    a[i] = rd()
for i in range(N-1, 0, -1):
    a[i] -= a[i-1]
p = 0
for i in range(1, N):
    p += max(0, a[i])
print((a[0] + p + 1) // 2)
Q = rd()
for _ in range(Q):
    l, r, x = rd(), rd(), rd()
    l -= 1
    if l != 0:
        p -= max(a[l], 0)
    a[l] += x
    if l != 0:
        p += max(a[l], 0)
    if r != N:
        p -= max(a[r], 0)
        a[r] -= x
        p += max(a[r], 0)
    print((a[0] + p + 1) // 2)
