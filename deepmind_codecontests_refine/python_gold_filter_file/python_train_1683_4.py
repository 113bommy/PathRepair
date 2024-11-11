n = int(input())-1
x, y = 1, 9
while n > x * y: n,x,y = n-x*y,x+1,y*10
a = str(10 ** (x - 1) + n // x)[n%x]
print(a)
