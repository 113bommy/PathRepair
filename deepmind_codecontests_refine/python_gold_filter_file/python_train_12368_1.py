W, H, x, y = map(int, input().split())
print(W*H/2, (1 if x==W/2 and y==H/2 else 0))