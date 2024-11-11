s=input()
from bisect import bisect_left as bl,bisect_right as br
if len(s)==26:
  if s=="zyxwvutsrqponmlkjihgfedcba":print(-1);exit()
  f=s[-1]
  p=[s[-1]]
  for i in range(2,26):
    if s[-i]>f:
      f=s[-i];p.append(f)
    else:print(s[:-i]+p[bl(p,s[-i])]);exit()
  print(chr(ord(s[0])+1))
else:
  f=sorted(list(set(list("aqzxswedcvfrtgbnhyujmkilop"))-set(list(s))))
  print(s+f[0])