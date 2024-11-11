import math

N = int(input())

for l in range(N):
    s = input()
    hh = int(s[0:2])
    mm = int(s[3:5])

    deg2 = 6 * mm
    deg1 = 30 * hh + deg2 / 12

    #print(deg1, deg2)
    d = abs(deg1-deg2)
    if d < 30 or 330 < d:
        print("alert")
    elif 90 <= d and d <= 270:
        print("safe")
    else:
        print("warning")

