w, h, x, y = map(int, input().split())
o = 1 if w/2==x and h/2==y else 0
print(w*h/2, o)
