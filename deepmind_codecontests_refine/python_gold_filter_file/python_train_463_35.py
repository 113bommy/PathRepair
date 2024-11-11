r, x, y, x1,y1 = [int(x) for x in input().split()]
distance = (abs(x-x1)**2+abs(y-y1)**2)**0.5
print(0 if distance==0 else int((distance-0.000000001)/(2*r))+1)