
F = input()

is24 = True
if F == "12": is24 = False


Time = input()

H = int(Time[0:2])

M = int(Time[3:5])

if is24:
    if H > 23:
        H = 10 + H%10
    if M > 59:
        M = 10 + M%10
else:
    if H > 12:
        if H%10 <= 2:
            H = 10 + H%10
        else:
            H = H%10
    if H == 0:
        H = 1
    if M > 59:
        M = 10 + M%10

print(str(H).zfill(2) + ":" + str(M).zfill(2))



