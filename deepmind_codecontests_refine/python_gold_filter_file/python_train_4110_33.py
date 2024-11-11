a,b,c,d = map(int, input().split())
misha = max(0.3*a, a-(a/250)*c)
vaysa = max(0.3*b, b-(b/250)*d)

if misha > vaysa:
    print("Misha")
elif misha < vaysa:
    print("Vasya")
else:
    print("Tie")