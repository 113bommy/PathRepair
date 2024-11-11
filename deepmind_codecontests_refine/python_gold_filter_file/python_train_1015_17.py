class SegmentTree():
  def __init__(self, n, oper, e):
    self.n = n
    self.oper = oper
    self.e = e
    self.log = (n - 1).bit_length()
    self.size = 1 << self.log
    self.data = [e] * (2 * self.size)

  def update(self, k):
    self.data[k] = self.oper(self.data[2 * k], self.data[2 * k + 1])

  def build(self, arr):
    #assert len(arr) <= self.n
    for i in range(self.n):
      self.data[self.size + i] = arr[i]
    for i in range(self.size-1,0,-1):
      self.update(i)

  def set(self, p, x):
    #assert 0 <= p < self.n
    p += self.size
    self.data[p] = x
    for i in range(1, self.log + 1):
      self.update(p >> i)

  def get(self, p):
    #assert 0 <= p < self.n
    return self.data[p + self.size]

  def prod(self, l, r):
    #assert 0 <= l <= r <= self.n
    sml = smr = self.e
    l += self.size
    r += self.size
    while l < r:
      if l & 1:
        sml = self.oper(sml, self.data[l])
        l += 1
      if r & 1:
        r -= 1
        smr = self.oper(self.data[r], smr)
      l >>= 1
      r >>= 1
    return self.oper(sml, smr)

  def all_prod(self):
    return self.data[1]


import sys
input = sys.stdin.buffer.readline

N, K = map(int, input().split())
A = [int(input()) for _ in range(N)]
maxA = max(A)
st = SegmentTree(maxA+1, max, 0)

for i in range(N):
  mm = st.prod(max(0,A[i]-K),min(maxA,A[i]+K)+1)+1
  st.set(A[i],mm)
ans = st.all_prod()
print(ans)