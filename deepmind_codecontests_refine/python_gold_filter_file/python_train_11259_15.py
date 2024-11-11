n, t = map(int,input().split())
b, dif = -1, 10000000000
for i in range( n ):
    s, d = map(int, input().split())
    a = t-s
    if a <= 0:
        d = -a
    else:
        d = (-a)%d
    if d < dif:
        b = i + 1
        dif = d

print( b )
