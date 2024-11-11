n = int(input())
a,b = divmod(n,2)
if b == 0:
  a -= 1
print(a)