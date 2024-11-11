import sys
print(sum(s[:-1]==s[-2::-1]for s in sys.stdin))
