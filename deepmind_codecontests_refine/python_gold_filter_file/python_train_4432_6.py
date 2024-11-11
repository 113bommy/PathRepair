import math

str = input()

n = int(str[:-1])
s = str[-1]

dict = {'a': 4, 'b': 5 , 'c' : 6, 'd':3, 'e':2, 'f':1}
k = dict.setdefault(s)
b = 0

if n%2 == 0:
    b = 1
else:
    b = 0

if n%4>0:
    z = n//4
else:
    z = n//4 -1
    
time = z*16 +  b*7 + k

print(time)