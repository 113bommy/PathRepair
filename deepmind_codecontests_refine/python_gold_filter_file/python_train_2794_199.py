x,a,b = map(int,input().split())
if abs(b-x) > abs(x-a):
    print("A")
else:
    print("B")