cnt = int(input ())

for i in range (cnt):
    readline =  input ().split( )
    loc_br = int(readline[0])
    loc_sr = int(readline[1])
    a = int(readline[2])
    b = int(readline[3])
    if (loc_sr - loc_br) % (a + b) == 0:
        print (int((loc_sr - loc_br) / (a + b)))
    else:
        print (-1)
