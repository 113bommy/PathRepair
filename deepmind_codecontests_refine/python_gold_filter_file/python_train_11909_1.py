from sys import stdin as read
from sys import stdout as out
n = int(read.readline())

if n % 2 == 0:
  out.write("-1")
else:
  res = " ".join(map(str,range(n)))
  out.write(res+"\n")
  out.write(res+"\n")
  out.write(" ".join(map(str, [(i+i)%n for i in range(n)])))
