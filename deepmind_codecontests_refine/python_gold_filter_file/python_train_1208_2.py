"""
Codeforces Round 430 Div 1 Problem A

Author  : chaotic_iak
Language: Python 3.5.2
"""

################################################### SOLUTION

pt = []
for i in range(500):
    pt.append(i*(i-1)//2)

def main():
    k, = read()
    ptr = 499
    res = ""
    for i in range(26):
        while pt[ptr] > k: ptr -= 1
        res += chr(97+i) * ptr
        k -= pt[ptr]
    return res

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
