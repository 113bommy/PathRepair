n = int(input())

turn = 'Mahmoud'
while True:
    if n % 2 == 0 and turn == 'Mahmoud':
        n -= n%2
        turn = 'Ehab'
    elif n % 2 !=0 and turn == 'Ehab':
        n -= n%2
        turn = 'Mahmoud'
    else:
        if turn == 'Mahmoud':
            turn = 'Ehab'
        else:
            turn = 'Mahmoud'
        break
        
print (turn)