import sys

c = 0
a = '11'

for i in ' '*int(input()):
  group = sys.stdin.readline()
  if a != group:
    c += 1
  a = group

print(c)