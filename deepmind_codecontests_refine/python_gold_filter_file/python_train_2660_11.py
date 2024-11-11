a, b, c, d = sorted(map(int, input().split()))
x = min(d - b - c, c - a - b)
if x>0:
    print("IMPOSSIBLE")
elif x<0:
    print("TRIANGLE")
else:
    print("SEGMENT")

