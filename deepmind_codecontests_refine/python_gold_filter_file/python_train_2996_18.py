import sys
input = sys.stdin.readline


class RollingHash:
    """文字列stringsの部分文字列のハッシュを構築する。O(N)"""
    def __init__(self, string):
        self.n = len(string)
        self.BASE = 1234
        self.MASK30 = (1 << 30) - 1
        self.MASK31 = (1 << 31) - 1
        self.MASK61 = (1 << 61) - 1
        self.MOD = self.MASK61
        self.hash = [0] * (self.n + 1)
        self.pow = [1] * (self.n + 1)

        for i, char in enumerate(string):
            self.hash[i + 1] = self.calc_mod(self.mul(self.hash[i], self.BASE)
                                             + ord(char))
            self.pow[i + 1] = self.calc_mod(self.mul(self.pow[i], self.BASE))

    def calc_mod(self, x):
        """x mod 2^61-1 を返す。"""
        xu = x >> 61
        xd = x & self.MASK61
        x = xu + xd
        if x >= self.MOD:
            x -= MASK61
        return x

    def mul(self, a, b):
        """a*b mod 2^61-1 を返す。"""
        au = a >> 31
        ad = a & self.MASK31
        bu = b >> 31
        bd = b & self.MASK31
        mid = ad * bu + au * bd
        midu = mid >> 30
        midd = mid & self.MASK30
        return self.calc_mod(au * bu * 2 + midu + (midd << 31) + ad * bd)

    def get_hash(self, l, r):
        """string[l:r]のハッシュ値を返す。O(1)"""
        res = self.calc_mod(self.hash[r]
                            - self.mul(self.hash[l], self.pow[r - l]))
        return res

    def merge(self, h1, h2, length2):
        """ハッシュ値h1と長さlength2のハッシュ値h2を結合する。O(1)"""
        return self.calc_mod(self.mul(h1, self.pow[length2]) + h2)

    def get_lcp(self, l1, r1, l2, r2):
        """string[l1:r2]とstring[l2:r2]の長共通接頭辞(Longest Common Prefix)の
        長さを求める。O(log|string|)
        """
        ng = min(r1 - l1, r2 - l2) + 1
        ok = 0
        while abs(ok - ng) > 1:
            mid = (ok + ng) // 2
            if self.get_hash(l1, l1 + mid) == self.get_hash(l2, l2 + mid):
                ok = mid
            else:
                ng = mid
        return ok


n = int(input())
s = [input()[:-1] for i in range(n)]


s.sort(key=len)
str_set = set()
cnt = 0

for string in s:
    string = string[::-1]  # stringの後ろから見る
    n = len(string)
    rh = RollingHash(string)

    for r in range(1, n + 1):
        if rh.get_hash(0, r) in str_set:
            cnt += 1

    set_char = set()
    for r in range(1, n + 1)[::-1]:
        h_str = rh.get_hash(0, r - 1)
        h_r = rh.get_hash(r - 1, r)
        set_char.add(h_r)
        for h1 in set_char:
            if h1 == h_r:
                continue
            h = rh.merge(h_str, h1, 1)
            if h in str_set:
                cnt += 1
    str_set.add(rh.get_hash(0, n))

print(cnt)