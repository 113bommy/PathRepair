a = int(input())
b = int(input())
d = abs(b-a)
if (d%2 == 0):
    print (int((d/2)*(d/2+1)))
else:
    x = (d-1)/2
    y = (d+1)/2
    print( int(x*(x+1)/2+y*(y+1)/2))
