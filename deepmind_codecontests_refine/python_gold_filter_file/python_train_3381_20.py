a, b, s = map(int, input().split())
p = abs(a)+abs( b)
if (s - p) % 2 == 0 and s >= p:
    print("Yes")
else:
    print("No")
