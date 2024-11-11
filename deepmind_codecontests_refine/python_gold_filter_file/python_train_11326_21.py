h, w, a, b = map(int, input().split())

for i in range(h):
  for j in range(w):
    print( 1 if (j<a)^(i<b) else 0, end = "" )
  print()