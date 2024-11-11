a = int(input())
s = "ROYGBIV"
if a > 7:
    print((s * (a // 7) + s[3:] * 2)[:a])
else:
    print(s[:a])
