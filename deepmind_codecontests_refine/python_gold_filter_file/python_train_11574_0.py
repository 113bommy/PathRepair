from collections import defaultdict
import sys
input = lambda: sys.stdin.readline().strip()

def f(x):
  cnt = 0
  for i in x:
    if i in "aeiou":
      cnt += 1
  return cnt 

def last_vowel(s):
  for i in s[::-1]:
    if i in "aeiou":
      return i 

n = int(input())
sarr = [input() for i in range(n)]

d = defaultdict(list)


for s in sarr:
  d[(f(s), last_vowel(s))].append(s)

same_same = []
same_different = defaultdict(list)
for i, j in d.items():
  if len(j) >= 2:
    if len(j) % 2 == 1:
      same_different[i[0]].append(j[-1])
      j.pop()
    for i in range(0, len(j), 2):
      same_same.append((j[i], j[i+1]))
  else:
    same_different[i[0]].append(j[0])

#print(same_same)

same_different_list = []
for i, j in same_different.items():
  if len(j) >= 2:
    if len(j) % 2 == 1:
      j.pop()
    
    for i in range(0, len(j), 2):
      same_different_list.append((j[i], j[i+1]))

#print(same_different_list)


ans = []

while same_same and same_different_list:
  ans.append((same_same[-1], same_different_list[-1]))
  same_same.pop()
  same_different_list.pop()

while len(same_same) >= 2:
  ans.append((same_same[-1], same_same[-2]))
  same_same.pop()
  same_same.pop()

print(len(ans))

for (b1, b2), (a1, a2) in ans:
  sys.stdout.write(a1 + " " + b1 + "\n")
  sys.stdout.write(a2 + " " + b2 + "\n")

