a, b, c, d = list(map(int, input().split()))

vasya = max((b*3)/10 , b - (b/250)  * d)
Misha = max((a*3)/10 , a - (a/250)  * c)


if vasya == Misha:
    print("Tie")
elif vasya > Misha:
    print("Vasya")
else:
    print("Misha")

