n = int(input()) // 3
s = list(input())
_0 = s.count("0")
__0 = 0
_1 = s.count("1")
__1 = 0
_2 = s.count("2")
__2 = 0
for i in range(len(s)):
    if s[i] == "0":
        __0 += 1
    elif s[i] == "1":
        __1 += 1
    elif s[i] == "2":
        __2 += 1
    if s[i] == "0" and __0 > n and _0 > n:
        if _1 < n:
            s[i] = "1"
            _1 += 1
            _0 -= 1
        elif _2 < n:
            s[i] = "2"
            _2 += 1
            _0 -= 1
    elif s[i] == "1" and _1 > n:
        if _0 < n:
            s[i] = "0"
            _0 += 1
            _1 -= 1
            __1 -= 1
        elif _2 < n and __1 > n:
            s[i] = "2"
            _2 += 1
            _1 -= 1
    elif s[i] == "2" and _2 > n:
        if _0 < n:
            s[i] = "0"
            _0 += 1
            _2 -= 1
        elif _1 < n:
            s[i] = "1"
            _1 += 1
            _2 -= 1
print("".join(s))