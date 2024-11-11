# Aizu Problem 0101: Aizu PR
#
import sys, math, os

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


N = int(input())
for _ in range(N):
    print(input().replace("Hoshino", "Hoshina"))