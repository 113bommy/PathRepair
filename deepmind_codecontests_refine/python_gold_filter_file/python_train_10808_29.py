a,b,c,x = map(int, input().split())
print("Yes" if abs(a-b)<=x and abs(c-b)<=x or abs(a-c) <= x else "No" )