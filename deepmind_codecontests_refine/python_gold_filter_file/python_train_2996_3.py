import sys
input = sys.stdin.readline


class RollingHash:
    def __init__(self, string):
        self.n = len(string)
        self.BASE = 1234
        self.MOD = (1 << 45) - 1
        self.hash = [0] * (self.n + 1)
        self.pow = [1] * (self.n + 1)

        for i, char in enumerate(string):
            self.hash[i + 1] = (self.hash[i] + ord(char)) * self.BASE % self.MOD
            self.pow[i + 1] = (self.pow[i] * self.BASE) % self.MOD

    def get_hash(self, l, r):
        """string[l:r]のハッシュ値を返す。O(1)"""
        res = (self.hash[r] - self.hash[l] * self.pow[r - l]) % self.MOD
        return res


n = int(input())
s = [input()[:-1] for i in range(n)]


s.sort(key=len)
str_set = set()
cnt = 0

for string in s:
    string = string[::-1]
    n = len(string)
    rh = RollingHash(string)

    for r in range(1, n + 1):
        if rh.get_hash(0, r) in str_set:
            cnt += 1

    set_char = set()
    for r in range(1, n + 1)[::-1]:
        set_char.add(string[r - 1])
        for char in set_char:
            if char == string[r - 1]:
                continue
            h = (rh.hash[r - 1] + ord(char)) * rh.BASE % rh.MOD
            if h in str_set:
                cnt += 1
    str_set.add(rh.get_hash(0, n))

print(cnt)