def inp():
  return map(int, input().split())

h1, h2 = inp()
k1, k2 = inp()
a, b, c, d = inp()

def point(x1, x2):
  return x1 * a + x2 * b + (x1 // 10) * c + (x2 // 20) * d

ph = point(h1, h2)
pk = point(k1, k2)
if ph > pk:
  print("hiroshi")
elif ph < pk:
  print("kenjiro")
else:
  print("even" )
