c =0
a = []
while c < 3:
    b = input()
    l = b.split()
    a.append(l)
    c +=1
if (int(a[0][0]) + int(a[0][1]) + int(a[1][0])) % 2 == 0 :
    print(1,end='')
else:
    print(0,end='')                                                                                    
if (int(a[0][1]) + int(a[0][0]) + int(a[0][2]) + int(a[1][1])) % 2 == 0 :
    print(1,end='')
else:
    print(0,end='')                                                                                
if (int(a[0][1]) + int(a[0][2]) + int(a[1][2])) % 2 == 0 :
    print(1)
else:
    print(0)
if (int(a[0][0]) + int(a[1][0]) + int(a[1][1]) + int(a[2][0])) % 2 == 0 :
    print(1,end='')
else:
    print(0,end='')
if (int(a[1][1]) + int(a[1][0]) + int(a[2][1]) + int(a[1][2]) + int(a[0][1])) % 2 == 0 :
    print(1,end='')
else:
    print(0,end='')
if (int(a[1][2]) + int(a[0][2]) + int(a[1][1]) + int(a[2][2])) % 2 == 0 :
    print(1)
else:
    print(0)
if (int(a[2][0]) + int(a[1][0]) + int(a[2][1])) % 2 == 0 :
    print(1,end='')
else:
    print(0,end='')
if (int(a[2][1]) + int(a[1][1]) + int(a[2][0]) + int(a[2][2])) % 2 == 0 :
    print(1,end='')
else:
    print(0,end='')
if (int(a[2][2]) + int(a[1][2]) + int(a[2][1])) % 2 == 0 :
    print(1)
else:
    print(0)