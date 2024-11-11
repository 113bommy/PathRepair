def is_midpoint(p1,p2,p3):
    if (p1[0]+p2[0])/2==p3[0] and (p1[1]+p2[1])/2==p3[1]:
        return True
    else:
        return False

def distance(p1,p2):
    return (((p2[0]-p1[0])**2)+((p2[1]-p1[1])**2))

def same_slope(p1,p2,p3):
    if is_midpoint(p1,p2,p3) or is_midpoint(p2,p1,p3) or is_midpoint(p1,p3,p2):
        return False
    elif distance(p1,p2)==distance(p2,p3):
        return True
    else:
        return False

a_x,a_y,b_x,b_y,c_x,c_y=map(int,input().split())
p1=[a_x,a_y]
p2=[b_x,b_y]
p3=[c_x,c_y]
if same_slope(p1,p2,p3):
    print("YES")
else:
    print("NO")