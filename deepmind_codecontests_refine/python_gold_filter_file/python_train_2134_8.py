x,y = map(int, input().split())
a1,a2 = map(int, input().split())
b1,b2 = map(int, input().split())
ans = False
if (a1+b2<=x and max(b1,a2)<=y) or (a1+b2<=y and max(b1,a2)<=x):
 ans = True
if a1+b1<=x and max(a2,b2)<=y or a1+b1<=y and max(a2,b2)<=x:
 ans = True
if a2+b1<=x and max(a1,b2)<=y or a2+b1<=y and max(a1,b2)<=x:
 ans = True
if a2+b2<=x and max(a1,b1)<=y or a2+b2<=y and max(a1,b1)<=x:
 ans = True
print("YES" if ans else "NO")