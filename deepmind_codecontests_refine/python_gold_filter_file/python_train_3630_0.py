def day(Y, m, d, Gregorian=True):
    from math import floor

    # ツェラーの公式
    if m <= 2:
        Y -= 1
        m += 12
    y = Y%100
    c = Y//100
    g = 5*c+floor(c/4) if Gregorian else 5-c
    return (d + floor(26*(m+1)/10) + y + floor(y/4) +  g) %7 # 0->土曜, 6->金曜

day_en = ["Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"]

while True:
    m, d = map(int, input().split())
    if m == 0:
        break
    print(day_en[day(2004, m, d)])

