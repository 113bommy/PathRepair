def long_numbers(s, t):
    m = max(len(s), len(t))
    for i in range(m):
        sn = '0'
        if len(s) - m + i >= 0:
            sn = s[len(s) - m + i]
        tn = '0'
        if len(t) - m + i >= 0:
            tn = t[len(t) - m + i]
        if sn < tn:
            return '<'
        if sn > tn:
            return ">"
    return "="


s1 = input()
s2 = input()
print(long_numbers(s1, s2))
