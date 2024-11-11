x = input().split(" ")
a, b, c, d = x
ac = max((3 * int(a) / 10), (int(a) - int(a)/250 * int(c)))
bd = max((3 * int(b) / 10), (int(b) - int(b)/250 * int(d)))
if ac == bd:
    print("Tie")
elif ac > bd:
    print("Misha")
else:
    print("Vasya")