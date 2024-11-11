a, b = map(int, input().split())
mark = True
while a > 0 and b > 0 and mark:
    mark = False
    if (a >= 2 * b and b > 0):
        a = a % (2 * b)
        mark = True
    if (b >= 2 * a and a > 0):
        b = b % (2 * a)
        mark = True
    
print(a, b)
    
