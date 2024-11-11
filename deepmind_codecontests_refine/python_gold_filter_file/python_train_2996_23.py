import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
mod = 10**23 + 117

d = {}

S = [input()[:-1] for i in range(n)]

S.sort(key = lambda x:len(x))

ans = 0
for s in S:
    if len(s) == 1:
        if -1 in d.keys():
            array = d[-1]
            ans += array[ord(s) - ord("a")]
        else: d[-1] = [0]*26
        d[-1][ord(s) - ord("a")] += 1
    else:
        h = 0
        cnt = [0]*26
        for t in s:
            cnt[ord(t) - ord("a")] += 1
        if -1 in d.keys():
            array = d[-1]
            for i in range(26):
                if cnt[i] > 0 and array[i] > 0:ans += 1
        for t in s[len(s) - 1:0:-1]:
            num = ord(t) - ord("a")
            h += num + 1
            h *= 29
            h %= mod
            cnt[num] -= 1
            if h in d.keys():
                array = d[h]
                for i in range(26):
                    if cnt[i] > 0 and array[i] > 0:ans += 1
        if h not in d.keys(): d[h] = [0]*26
        d[h][ord(s[0]) - ord("a")] += 1
print(ans)
