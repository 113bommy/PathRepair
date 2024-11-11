o = input()
e = input()
r = ''

for i in range(len(o)):
  r += o[i]
  if i < len(e):
    r += e[i]
print(r)