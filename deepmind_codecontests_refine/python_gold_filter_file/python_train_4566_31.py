w, a, b = [ int(v) for v in input().split() ]

print(max(abs(a-b) - w, 0))