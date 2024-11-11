a, b, c = map(int, input().split())
print("Yes" if 4*a*b<(c-b-a)**2 and c-b-a>0 else "No")
