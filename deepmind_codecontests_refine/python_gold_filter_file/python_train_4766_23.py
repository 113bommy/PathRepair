x, y = map(int, input().split())
print(['No', 'Yes'][y in [2*x+2*t for t in range(x+1)]])