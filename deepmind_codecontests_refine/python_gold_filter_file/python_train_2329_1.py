s = input()
x = s.count('x')
y = len(s) - x
print(['y' , 'x'][x>y]*abs(y-x))
