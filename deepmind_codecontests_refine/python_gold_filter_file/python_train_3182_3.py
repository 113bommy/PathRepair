from collections import Counter
n = int(input())
a = list(map(int, input().split()))
b = True
for i in range(n):
  s = input()
  c = Counter(s)
  boin = c['a']+c['e']+c['i']+c['o']+c['u']+c['y']
  if a[i] != boin :
    b=False

if b:
  print("YES")
else:
  print("NO")