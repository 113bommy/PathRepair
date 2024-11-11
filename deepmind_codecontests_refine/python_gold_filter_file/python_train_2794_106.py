x,y,z=map(int,input().split())
if abs(y-x) < abs(z-x):
    print("A")
else:
    print("B")