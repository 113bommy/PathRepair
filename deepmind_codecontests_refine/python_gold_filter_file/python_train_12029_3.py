w = int(input())
house = 1234567
car = 123456
comp = 1234
q = False
b = 0
c = 0

while c <= w//comp and q == False and w >= comp:
    while b <= w//car and q == False and w >= car:
        if (w - c*comp - b*car)%house == 0 and (w - c*comp - b*car) >= 0:
                q = True
                break
        b += 1
    if (w - c*comp - b*car)%house == 0 and (w - c*comp - b*car) >= 0:
        q = True
        break
    c += 1
    b = 0
if q == True:
    print("YES")
else:
    print("NO")