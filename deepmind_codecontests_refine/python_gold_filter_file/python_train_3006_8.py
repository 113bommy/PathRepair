from math import sqrt
n = int(input())

for i in range(n):
    l = input()
    x1,y1,x2,y2,x3,y3=map(float,l.split(' '))
    a_2 = (x1 - x2)**2 + (y1 - y2)**2
    b_2 = (x2 - x3)**2 + (y2 - y3)**2
    c_2 = (x3 - x1)**2 + (y3 - y1)**2
    cos_a_2 = (b_2 + c_2 - a_2)**2/(4* b_2 * c_2)
    sin_a_2 = 1 - cos_a_2
    r = round(sqrt(a_2/sin_a_2)/2,3)
    a = (x1**2 - x3**2 + y1**2 - y3**2)*(x2 - x1)
    b = (x1**2 - x2**2 + y1**2 - y2**2)*(x3 - x1)
    c = (y2 - y1)*(x3 - x1)
    d = (y3 - y1)*(x2 - x1)
    py = round((a-b)/(c-d)/2,3)
    a = (x1**2 - x3**2 + y1**2 - y3**2)*(y2 - y1)
    b = (x1**2 - x2**2 + y1**2 - y2**2)*(y3 - y1)
    c = (x2 - x1)*(y3 - y1)
    d = (x3 - x1)*(y2 - y1)
    px = round((a-b)/(c-d)/2,3)
    print('%.3f %.3f %.3f' %(px, py, r))