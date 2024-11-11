s = input().split()
n, k = int(s[0]), int(s[1])
s = input()
mn = n
count = 0
for i in range(k):
  t = s.count(chr(65+i))
  count+=t
  if t<mn:
    mn = t

if mn!=0:
  print(mn*k+n-count)
else:
  print(0)