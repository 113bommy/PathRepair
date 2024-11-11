a = input()
A = list(map(int,list(a.split())))
r = A[0]
x1 = A[1]
y1 = A[2]
x2 = A[3]
y2 = A[4]
m = (abs(x1-x2))**2+(abs(y1-y2))**2
if (m**(1/2))%(2*r) == 0:
    print(int((m**(1/2))//(2*r)))
else:
    print(int((m**(1/2))//(2*r))+1)
