from sys import stdin
from math import sqrt

def valid_discriminant(a,b,c):
    # print("a = {}".format(a))
    # print("b = {}".format(b))
    # print("c = {}".format(c))
    d = (b*b) - (4 * a * c)
    # print("d = {}".format(d))
    if d < 0:
        return False, -1
    else:
        return True, d



def get_y2(a,b,d):
    b = (-1 * b)
    y1 = (b + sqrt(d)) / (2*a)
    y2 = (b - sqrt(d)) / (2*a)
    # print(y1)
    # print(y2)
    #get the plus one
    return max(y1,y2)
    #return (y1,y2)



n,r = stdin.readline().split()
n = int(n)
r = int(r)
dist = r + r
inputs = stdin.readline().split()
xinput = [int(item) for item in inputs[1:]]

listcord = []
cord = {}
cord['y'] = r
cord['x'] = int(inputs[0])
listcord.append(cord)
for index,x2 in enumerate(xinput):
    y2 = r
    for _cord in listcord:
        # print("index {} : {}".format(index,_cord))
        x1 = _cord['x']
        y1 = _cord['y']
        a = 1
        b = -2 * y1
        xdiff = x2 - x1
        c = (y1*y1) - (dist * dist) + (xdiff * xdiff)
        flag, d = valid_discriminant(a,b,c)
        if flag:
            temp_y2 = get_y2(a,b,d)
        else:
            temp_y2 = r
            continue
        if y2 < temp_y2:
            y2 = temp_y2

    cord = {}
    cord['y'] = y2
    cord['x'] = x2
    listcord.append(cord)
y = " ".join([str(item['y']) for item in listcord])
print(y)
