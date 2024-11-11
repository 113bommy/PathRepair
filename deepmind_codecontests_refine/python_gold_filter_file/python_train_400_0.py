# Aizu Problem 00127: Pocket Pager Input
#
import sys, math, os, copy

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


code = {1: "afkpuz", 2: "bglqv.", 3: "chmrw?", 4: "dinsx!", 5: "ejoty "}

def pocket_pager(string):
    if len(string) % 2 == 1:
        return "NA"
    res = ""
    for k in range(len(string) // 2):
        i = int(string[2*k])
        j = int(string[2*k+1])
        if not 1 <= i <= 6 or not 1 <= j <= 5:
            return "NA"
        res += code[j][i-1]
    return res


for line in sys.stdin:
    print(pocket_pager(line.strip()))