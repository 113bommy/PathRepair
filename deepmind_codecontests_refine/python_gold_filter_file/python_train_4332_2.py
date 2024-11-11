import sys

input = sys.stdin.readline

def solve():
    s = input().strip()
    t = input().strip()
    t_dict = {}
    s_dict = {}
    for c in t:
        if c in t_dict:
            t_dict[c] += 1
        else:
            t_dict[c] = 1
            s_dict[c] = 0
    for c in s:
        if c in s_dict:
            s_dict[c] += 1
        elif c != '?':
            s_dict[c] = 1
    def good(x):
        return sum([max(0, x * t_dict[c] - s_dict[c]) for c in t_dict]) <= s.count('?')
    l = 0
    r = len(s) + 1
    while r - l > 1:
        m = (l + r) // 2
        if good(m):
            l = m
        else:
            r = m
    s = list(s)
    chars = [c for c in t_dict]
    i = 0
    for j in range(len(s)):
        while i < len(chars) and s_dict[chars[i]] >= l * t_dict[chars[i]]:
            i += 1
        if i == len(chars) and s[j] == '?':
            s[j] = 'x'
        elif s[j] == '?':
            s[j] = chars[i]
            s_dict[chars[i]] += 1
    return ''.join(s)


print(solve())
