s = int(input())
for i in range (s):
  l = int(input())
  if l <= 2:
    print (0)
  elif l % 2 == 0:
    print((l//2)-1)
  elif l %2 != 0:
    print(l//2)