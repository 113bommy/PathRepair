import sys
for s in sys.stdin:
 if s=='0 0\n':break
 print(*sorted(map(int,s.split())))