import sys

s = "abcdefghijklmnopqrstuvwxyz"

for line in sys.stdin:
  while True:
    if ("the" in line) or ("this" in line) or ("that" in line):
      break
    else:
      l = [i for i in line]
      for i in range(len(l)):
        if l[i] in s:
          a = s.index(l[i])
          l[i] = l[i].replace(l[i],s[(a+1)%26])
      line = "".join(l)
  print(line.rstrip())