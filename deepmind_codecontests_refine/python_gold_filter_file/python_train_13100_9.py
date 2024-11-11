n = int(input())
a = sorted(list(map(int,input().split())),reverse = True)
use = []
flag = -1
for i in range(n):
  if flag == a[i]:
    use.append(a[i])
    flag = -1
  else:
    flag = a[i]
if len(use)<2:
  print(0)
else:
  use.sort(reverse =True)
  print(use[0]*use[1])