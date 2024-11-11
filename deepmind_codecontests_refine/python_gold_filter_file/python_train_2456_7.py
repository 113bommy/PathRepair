
n,k = map(int,input().split(" "))
p = list(map(int,input().split(" ")))
o = []

for x in p:
  o.append(x%k)

ruzne = False
x = o[0]
for num in o:
  if num != x:
    ruzne = True
if ruzne:
  print("-1")
else:
  kroky = 0
  mn = min(p)
  for i in range(n):
    kroky += (p[i] - mn) / k
  print(int(kroky))