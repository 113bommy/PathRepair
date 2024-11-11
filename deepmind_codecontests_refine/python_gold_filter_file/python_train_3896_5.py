r1,c1,r2,c2=map(int,input().split())

def f():
    if abs(r1-r2)==abs(c1-c2):
        return 1
    elif (r1+c1)%2==(c2+r2)%2:
        return 2
    else:
        return 0

def k():
    dx=abs(r1-r2)
    dy=abs(c1-c2)
    return max(dx,dy)

def r():
    if r1==r2 or c1==c2:
        return 1
    else:
        return 2
    
print(r(),f(),k())