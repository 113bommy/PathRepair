w = input()
for c in w:
  if w.count(c)&1:
    print('No')
    exit()
print('Yes')