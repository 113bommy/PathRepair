a = input()
a=a.split()
a[0] = int(a[0])
a[1] = int(a[1])
a[2] = int(a[2])
a[3] = int(a[3])


max1= (3*a[0])/10
if (int(a[0] - (a[0]/250)*a[2] )> max1):
    max1 =a[0] - (a[0]/250)*a[2]


max2= (3*a[1])/10
if (a[1] - (a[1]/250)*a[3] )> max2 :
    max2 = int(a[1] - (a[1]/250)*a[3])

if (max1 > max2):
    print("Misha")

if(max2 > max1):
    print("Vasya")

if(max1==max2):
    print("Tie")
