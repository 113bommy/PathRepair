check = ["6","7","8","9","T","J","Q","K","A"]
trump = input()
fir,sec = input().split()
if(fir[1] != sec[1]):
    if fir[1] == trump:
        print("YES")
    else:
        print("NO")
else:
    i1 = check.index(fir[0])
    i2 = check.index(sec[0])
    if i1 > i2:
        print("YES")
    else:
        print("NO")
