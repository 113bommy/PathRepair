s = input()
h = int(s[0] + s[1])
t = int(s[3] + s[4])
tt, hh = t, h
li = []
#print(h, t)
f = 0
for i in range(10000):
    t += 1
    if t > 59:
        t = 0
        if h == 23:
            h = 0
            print("00:00")
            break
        else:
            h += 1
            time = ""
            if h < 10:
                time += '0' + str(h)
            else:
                time += str(h)
            time += ':' + "00"
            if time == time[::-1]:
                print(time)    
                break
    else:
        time = ""
        if h < 10:
            time += '0' + str(h) + ':'
        else:
            time += str(h) + ':'
        if t < 10:
            time += '0' + str(t)
        else:
            time += str(t)
        if time == time[::-1]:
            print(time)
            break
