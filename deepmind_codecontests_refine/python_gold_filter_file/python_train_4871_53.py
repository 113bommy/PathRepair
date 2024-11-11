h, w = list(map(int, input().split()))
print( (h*w) // 2 + (h*w) % 2 if h != 1 and w != 1 else 1)