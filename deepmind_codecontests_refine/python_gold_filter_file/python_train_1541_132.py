a, b, c = map(int, input().split())
print("bust" if a+b+c > 21 else "win")