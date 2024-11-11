import random
d = int(input())
c = list(map(int, input().split()))
s = []
for i in range(d):
  s = list(map(int, input().split()))
  print(1+s.index(max(s)))