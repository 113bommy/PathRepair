h, m = map(int, input().split(":"))
h %= 12
print(0.5*(60*h+m), 6*m)