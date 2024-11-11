c,a, b  = [ int(x) for x in input().split() ]
if a%c != 0 and b < c: print('-1')
elif b%c != 0 and a < c: print('-1')
else: print(str(a//c + b//c))