a=[]
import sys
for s in sys.stdin:
 s=s.strip()
 if s=='0 0':break
 a.append(s)
for t in a:
 print(*sorted(map(int,t.split())))