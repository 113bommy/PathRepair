import sys
print(sum(e[:-1]==e[-2::-1]for e in sys.stdin))
