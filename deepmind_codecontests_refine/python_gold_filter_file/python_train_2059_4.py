a,v = map(int,input().split())
b,w = map(int,input().split())
t = int(input())
if abs(b-a) + w*t  - v*t <= 0:
    print("YES")
else:
    print("NO")