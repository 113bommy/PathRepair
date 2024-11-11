a,b,c = map(int, input().split())
print(max(a - c, 0), max(b + min(a - c, 0), 0))