n, x, y = map(int, input().split())
if x > y:
     print (n)
else:
     print ((len([t for t in map(int, input().split()) if t <= x]) + 1) // 2)