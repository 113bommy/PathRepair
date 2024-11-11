def solve_eq(a,b,c):
    return (-b-(b**2-4*a*c)**0.5)/(2*a),(-b+(b**2-4*a*c)**0.5)/(2*a)

def ret_line(x1,y1,x2,y2):
    k = (y1-y2)/(x1-x2)
    d = y1-k*x1
    return k,d
    
x,y,r = map(float,input().split())
q = int(input())
x1,y1,x2,y2 = [],[],[],[]
for i in range(q):
    arr = list(map(float,input().split()))
    x1.append(arr[0])
    y1.append(arr[1])
    x2.append(arr[2])
    y2.append(arr[3])

for i in range(q):
    if x1[i] != x2[i]:
        k,d = ret_line(x1[i],y1[i],x2[i],y2[i])
        p1,p2 = solve_eq(1+k**2,2*k*d-2*k*y-2*x,x**2+y**2+d**2-2*y*d-r**2)
        print(p1,k*p1+d,p2,k*p2+d)
    if x1[i] == x2[i]:
        p1,p2 = solve_eq(1,-2*y,y**2+(x1[i]-x)**2-r**2)
        print(x1[i],p1,x1[i],p2)