a, b, c, d = list(map(int, input().split()))
y = c
otvet = 0
for x in range(a, b+1):
    z = x + y - 1
    tr_xy = min(z, d) - c + 1
    y_kolvo = min(z-c, c-b)
    y_v_z = max(0, min(z-d, y_kolvo))
    an = tr_xy - y_kolvo + y_v_z
    otvet += (y_v_z) * tr_xy + ((tr_xy * tr_xy + tr_xy - an * an + an)//2)
print(otvet)
