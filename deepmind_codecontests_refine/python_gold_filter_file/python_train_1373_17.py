rects = []
for i in range(3):
    rects.append([int(x) for x in input().split()])

def completeCoverUp(a, b):
    if(b[0]<=a[0]<=b[2] and b[0]<=a[2]<=b[2] and b[1]<=a[1]<=b[3] and b[1]<=a[3]<=b[3]):
        return True
    else:
        return False 
def fullIntersect(a, b):
    if(b[1]<=a[1]<=b[3] and b[0]<=a[0]<=b[2] and b[0]<=a[2]<=b[2]):
        return  [a[0], b[3], a[2], a[3]]
    elif(b[1]<=a[3]<=b[3] and b[0]<=a[0]<=b[2] and b[0]<=a[2]<=b[2]):
        return [a[0], a[1], a[2], b[1]]
    elif(b[0]<=a[0]<=b[2] and b[1]<=a[3]<=b[3] and b[1]<=a[1]<=b[3]):
        return [b[2], a[1], a[2], a[3]]
    elif(b[0]<=a[2]<=b[2] and b[1]<=a[3]<=b[3] and b[1]<=a[1]<=b[3]):
        return [a[0], a[1], b[0], a[3]]
    else:
        return a

if(completeCoverUp(rects[0], rects[1]) or completeCoverUp(rects[0], rects[2])):
    print("NO")
else:
    remainingRect = fullIntersect(rects[0], rects[1])
    if(completeCoverUp(remainingRect, rects[2])):
        print("NO")
    else:
        print("YES")


