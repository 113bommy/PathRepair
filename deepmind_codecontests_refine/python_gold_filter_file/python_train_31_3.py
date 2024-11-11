n, x, y = map(int, input().split())
print(max(0, int(n/100*y-x+0.9999999999)))