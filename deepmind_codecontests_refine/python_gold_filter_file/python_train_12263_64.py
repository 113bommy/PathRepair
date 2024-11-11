n = int(input()) * 25
r = (n + 24)//27
print((r, ':(')[r * 27 < n])
