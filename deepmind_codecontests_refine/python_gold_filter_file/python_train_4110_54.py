a, b, c, d = map(int, input().split())
misha = max((3*a)/10, a - (a/250)*c)
vasya = max((3*b)/10, b - (b/250)*d)
if misha > vasya:
    print("Misha")
elif vasya > misha:
    print("Vasya")
else:
    print("Tie")
