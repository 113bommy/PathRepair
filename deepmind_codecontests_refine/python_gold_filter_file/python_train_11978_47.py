W, H, x, y, r = map(int, input().split())
print( 'Yes' if r <= x <= W - r and r <= y <= H - r else 'No')