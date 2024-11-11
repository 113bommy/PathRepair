w,a,b = map(int,input().split())
if abs(b-a) < w:
    print(0)
else:
    print(abs(b-a)-w)