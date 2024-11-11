[ind, x, unit] = input().split(" ")
if unit == "week":
    print(53 if ind == "5" or ind == "6" else 52)
else:
    print(12 if int(ind) <= 29 else (11 if int(ind) <= 30 else 7))
