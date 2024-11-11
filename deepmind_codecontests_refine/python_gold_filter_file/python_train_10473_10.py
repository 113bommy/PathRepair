m,b = input().strip().split()
m,b = int(m),int(b)

sum_s = []
x_zero = m*b
y_zero = b
for i  in range(0,b*m + 1,m):
  x = i
  y = b - i/m
  y =int(y)
  s = ((1+y)*y//2)*(x+1)
  s += ((1+x)*x//2)*(y+1)
  sum_s.append(s)
print(max(sum_s))
  

