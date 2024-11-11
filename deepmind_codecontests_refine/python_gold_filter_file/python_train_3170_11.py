a = {}
n = int(input())
for i in range(n):
  s = input()
  try:
    a[s] += 1
  except:
    a[s] = 1
for i in a.keys():
  if a[s]>a[i]:
    print(s)
    exit(0)
  elif a[s]!=a[i]:
    print(i)
    exit(0)
print(s)