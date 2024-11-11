n1 = list(input())
n2 = list(input())
n = list(input())
flag = False
for i in n1:
  if i in n:
    n.remove(i)
  else:
    flag = True
for i in n2:
  if i in n:
    n.remove(i)
  else:
    flas = True
print("YES" if n == [] and flag == False else "NO")