[w,h,x,y,r] = map(int, input().split())
print("Yes" if r <= x and x <= w - r and r <= y and y <= h - r else "No")