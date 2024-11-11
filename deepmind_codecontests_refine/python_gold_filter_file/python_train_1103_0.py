"""
Codeforces Round 427 Div 2 Problem B

Author  : chaotic_iak
Language: Python 3.5.2
"""

################################################### SOLUTION

def main():
    k, = read()
    n = input()
    s = [0]*10
    for c in n:
        s[ord(c)-48] += 1
    k -= sum(i*s[i] for i in range(10))
    ct = 0
    for i in range(9):
        if k <= 0: return ct
        tm = min(s[i], (k+9-i-1)//(9-i))
        ct += tm
        k -= tm*(9-i)
    return ct

#################################################### HELPERS

def read(callback=int):
    return list(map(callback, input().strip().split()))

def write(value, end="\n"):
    if value is None: return
    try:
        if not isinstance(value, str):
            value = " ".join(map(str, value))
    except:
        pass
    print(value, end=end)

write(main())
