from operator import itemgetter
import sys
import bisect
input = sys.stdin.readline


class BIT():
    """区間加算、区間取得クエリをそれぞれO(logN)で答える
    add: 区間[l, r)にvalを加える
    get_sum: 区間[l, r)の和を求める
    l, rは0-indexed
    """
    def __init__(self, n):
        self.n = n
        self.bit0 = [0] * (n + 1)
        self.bit1 = [0] * (n + 1)

    def _add(self, bit, i, val):
        i = i + 1
        while i <= self.n:
            bit[i] += val
            i += i & -i

    def _get(self, bit, i):
        s = 0
        while i > 0:
            s += bit[i]
            i -= i & -i
        return s

    def add(self, l, r, val):
        """区間[l, r)にvalを加える"""
        self._add(self.bit0, l, -val * l)
        self._add(self.bit0, r,  val * r)
        self._add(self.bit1, l,  val)
        self._add(self.bit1, r, -val)

    def get_sum(self, l, r):
        """区間[l, r)の和を求める"""
        return self._get(self.bit0, r) + r * self._get(self.bit1, r) \
               - self._get(self.bit0, l) - l * self._get(self.bit1, l)

#座標圧縮したリストを返す
def compress(array):
    n = len(array)
    m = len(array[0])
    set_ = set()
    for i in array:
        for j in i:
            set_.add(j)
    array2 = sorted(set_)
    memo = {value : index for index, value in enumerate(array2)}
    
    for i in range(n):
        for j in range(m):
            array[i][j] = memo[array[i][j]]
    return array, len(memo)


n = int(input())
info = [list(map(int, input().split())) for i in range(n)]
info, m = compress(info)

"""
for i in range(n):
    a1, a2, b1, b2 = info[i]
    for j in range(i+1, n):
        c1, c2, d1, d2 = info[j]
        if (max(a1, c1) <= min(a2, c2)) ^ (max(b1, d1) <= min(b2, d2)):
            print(2)
"""

info = sorted(info, key = itemgetter(0))

bi = [None] * n
for i in range(n):
    bi[i] = (i, info[i][1])
bi = sorted(bi, key = itemgetter(1))
bii = [v for i, v in bi]

bit = BIT(m)
tmp = 0
for i in range(n):
    l, r, l2, r2 = info[i]    
    ind = bisect.bisect_left(bii, l)
    while tmp < ind:
        ii = bi[tmp][0]
        bit.add(info[ii][2], info[ii][3] + 1, 1)
        tmp += 1
    if bit.get_sum(l2, r2 + 1) >= 1:
        print("NO")
        exit()

for i in range(n):
    info[i][0], info[i][1], info[i][2], info[i][3] = info[i][2], info[i][3], info[i][0], info[i][1]

info = sorted(info, key = itemgetter(0))

bi = [None] * n
for i in range(n):
    bi[i] = (i, info[i][1])
bi = sorted(bi, key = itemgetter(1))
bii = [v for i, v in bi]

bit = BIT(m)
tmp = 0
for i in range(n):
    l, r, l2, r2 = info[i]    
    ind = bisect.bisect_left(bii, l)
    while tmp < ind:
        ii = bi[tmp][0]
        bit.add(info[ii][2], info[ii][3] + 1, 1)
        tmp += 1
    if bit.get_sum(l2, r2 + 1) >= 1:
        print("NO")
        exit()
print("YES")