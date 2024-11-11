a = int(input())
x = 0
z = 0
y = 0
v = 0
w = 0
if a >= 100:
  x = a // 100
  a = a%100
if a >= 20: 
  y = a // 20
  a = a%20
if a >= 10:
  z = a //10
  a = a%10
if a >= 5:
  v = a // 5
  a = a%5
if a >= 1:
  w = a // 1

b = x + y + z + w + v

print(b)