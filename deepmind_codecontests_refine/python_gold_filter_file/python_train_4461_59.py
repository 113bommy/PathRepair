l = input().split()
for i in range(3):
  if l.count(l[i]) == 1:
    print(l[i])