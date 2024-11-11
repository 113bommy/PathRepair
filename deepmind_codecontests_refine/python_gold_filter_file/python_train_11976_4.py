w, h, x, y, r = map(int, input().split())
if(min([x, y, w - x, h - y]) >= r):
    print("Yes")
else:
    print("No")