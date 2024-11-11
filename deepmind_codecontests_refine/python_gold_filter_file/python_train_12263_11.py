import math

N = int(input())
x = math.ceil(N/1.08)

if x*1.08//1 == N:
  print(x)

else:
  print(":(")
