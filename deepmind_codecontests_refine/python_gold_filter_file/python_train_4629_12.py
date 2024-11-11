##24 Game Trial 1
n = int(input())

if (n>5):
    #stuff
    print('YES')
    print(str(n) + ' - ' + str(n-4) + ' = ' + '4')
    print(str(n-1) + ' - ' + str(n-3) + ' = ' + '2')
    print(str(n-2) + ' - ' + str(n-5) + ' = ' + '3')
    print('4'+ ' * ' + '2' + ' = ' + '8')
    print('8' + ' * ' + '3' + ' = ' + '24')
    if ((n-6)%2 == 0):
        for i in range(n-6,1,-2):
            #(n-6 - n-7)
            print( str(i) + ' - ' + str(i-1) + ' = ' + str(i-(i-1)))
            print('24' + ' * ' + '1' + ' = ' + '24')
    else:
        for i in range(n-6,2,-2):
            print( str(i) + ' - ' + str(i-1) + ' = ' + str(i-(i-1)))
            print('24' + ' * ' + '1' + ' = ' + '24')
        print('24' + ' * ' + '1' + ' = ' + '24')

elif(n == 4):
    print('YES')
    print('4' + " * " + '3' + " = " + '12')
    print('2' + " * " + '1' + " = " + '2')
    print('12' + " * " + '2' + " = " + '24')
elif(n == 5):
    print('YES')
    print('5' + " - " + '1' + " = " + '4')
    print('4' + " - " + '2' + " = " + '2')
    print('4' + " * " + '2' + " = " + '8')
    print('8' + " * " + '3' + " = " + '24')
    
else:
    print("NO")