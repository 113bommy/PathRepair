n = int(input())
x = [int(x) for x in list(str(n))]
x = x[::-1]
for i in x:
    if i == 0:
        print('O-|-OOOO')
    elif i == 1:
        print('O-|O-OOO')
    elif i == 2:
        print('O-|OO-OO')
    elif i == 3:
        print('O-|OOO-O')
    elif i == 4:
        print('O-|OOOO-')
    elif i == 5:
        print('-O|-OOOO')    
    elif i == 6:
        print('-O|O-OOO')
    elif i == 7:
        print('-O|OO-OO')
    elif i == 8:
        print('-O|OOO-O')
    elif i == 9:
        print('-O|OOOO-')