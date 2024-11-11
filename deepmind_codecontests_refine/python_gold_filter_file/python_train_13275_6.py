n = int(input()) % 360
if 45 < n <= 135:
    print(1)
elif 135 < n <= 225:
    print(2)
elif 225 < n < 315:
    print(3)
else:
    print(0)
