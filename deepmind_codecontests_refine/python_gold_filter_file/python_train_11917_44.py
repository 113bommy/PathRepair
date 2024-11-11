n = int(input())
a = 0
b = 0
while n > (a + b):
    b = b + 1
    a = a + b
    n = n - a
print (b)