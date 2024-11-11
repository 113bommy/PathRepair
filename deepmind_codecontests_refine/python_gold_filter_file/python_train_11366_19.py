def nod(a,b):
      while a != b:
            a, b = max(a,b), min(a,b)
            if a % b == 0:
                  a -= (a // b - 1) * b
            else:
                  a -= (a // b) * b
      return a
a, b, n = [int(x) for x in input().split()]
k = a
f = True
while True:
      if n == 0:
            break
      t = nod(k, n)
      if t > n:
            break
      n -= t
      if f:
            k = b
      else:
            k = a
      f = not f
print(1 if f else 0)
