abc="abcdefghijklmnopqrstuvwxyz"
import collections
table=collections.defaultdict(int)
for i in range(26):
  table[abc[i]]=i
table2=collections.defaultdict(int)
s=input()
for i in reversed(range(len(s)+1)):
  k=0
  if i < len(s):
    k=table[s[i]]+1
  for j in range(k,26):
    if abc[j] in s[:i]:
      continue
    else:
      print(s[:i]+abc[j])
      exit(0)
print(-1)