s="CODEFESTIVAL2016"
t=input()
a=0
for c, d in zip(s, t):
  if c != d:
    a += 1
print(a)
