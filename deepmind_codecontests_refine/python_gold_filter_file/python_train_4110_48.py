data  = [int(k) for k in input().split()]
Misha=  max((3*data[0]/10), data[0] - (data[0]/250)*data[2])
Vasya = max((3*data[1]/10), data[1] - (data[1]/250)*data[3])

if Misha == Vasya:
    print("Tie")
elif Misha > Vasya:
    print("Misha")
else:
    print("Vasya")