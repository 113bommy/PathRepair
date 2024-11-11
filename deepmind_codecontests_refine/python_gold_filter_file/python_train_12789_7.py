odd = list(input())
even = list(input())+ [""]

for x, y in zip(odd, even):
  print(x+y, end="")

