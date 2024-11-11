import sys
import math

def fn(r,x,y,x1,y1):
    d = math.sqrt((x-x1)**2 + (y-y1)**2)
    if d%(2*r)==0:
        out = int(d/2/r)
    else:
        out = int(d/2/r)+1
    return out

if __name__ == '__main__':    
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    r = data[0]
    x = data[1]
    y = data[2]
    x1 = data[3]
    y1 = data[4]
    print(fn(r,x,y,x1,y1))
    