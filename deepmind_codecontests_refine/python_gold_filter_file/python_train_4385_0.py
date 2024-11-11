x, y, z, t1, t2, t3=map(int,input().split())

tp=abs(x-y)*t1
tl=abs(x-z)*t2 + 3*t3+abs(x-y)*t2
if tl<=tp:
    print("YES")
else:
    print("NO")
