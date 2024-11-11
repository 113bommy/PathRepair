"""
Codeforces Problem

Author  : chaotic_iak
Language: Python 3.4.3
"""

################################################### SOLUTION

def main():
    l,r,k = read()
    ct = 1
    printed = False
    while ct <= r:
        if ct >= l:
            write(ct)
            write(" ")
            printed = True
        ct *= k
    if not printed:
        return -1

#################################################### HELPERS

def read(typ=int):
    # None: String, non-split
    # Not None: Split
    input_line = input().strip()
    if typ is None:
        return input_line
    return list(map(typ, input_line.split()))

def write(s="\n"):
    if s is None: s = ""
    if isinstance(s, list): s = " ".join(map(str, s))
    s = str(s)
    print(s, end="")

write(main())
