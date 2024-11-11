class SegmentTree:
    def __init__(self, iterable, op, e):
        n = len(iterable)
        self._op = op
        self._e = e
        self._size = n
        t = 1 << (n - 1).bit_length()
        self._offset = t - 1
        self._data = [e] * (t * 2 - 1)
        self._data[self._offset:self._offset + self._size] = iterable
        for i in range(self._offset - 1, -1, -1):
            self._data[i] = op(self._data[i * 2 + 1], self._data[i * 2 + 2])
 
    def __getitem__(self, key):
        return self._data[self._offset + key]
 
    def __setitem__(self, key, value):
        op = self._op
        data = self._data
        i = self._offset + key
        data[i] = value
        while i >= 1:
            i = (i - 1) // 2
            data[i] = op(data[i * 2 + 1], data[i * 2 + 2])
 
    def query(self, start, end):
        op = self._op
        res = self._e
        l = self._offset + start
        r = self._offset + end
        while l < r:
            if l & 1 == 0:
                res = op(res, self._data[l])
            if r & 1 == 0:
                r -= 1
                res = op(res, self._data[r])
            l = l // 2
            r = r // 2
        return res
    
    def getTop(self):
        return self._data[0]
 
N,K=map(int,input().split())
A = []
for i in range(N):
  a = int(input())
  A.append(a)
 
A_MAX = 300000
dp = [0]*(A_MAX+5)
 
st = SegmentTree(dp,max,0)

for i in range(N):
  s = max(A[i]-K, 0)
  e = min(A[i]+K+1, A_MAX+1)
  st[A[i]] = st.query(s, e) + 1
print(st.getTop())
