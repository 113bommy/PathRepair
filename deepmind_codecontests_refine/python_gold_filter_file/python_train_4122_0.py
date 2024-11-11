x = str(eval(input()))
for t in x:
    for i in range(ord(t)):
        print('+', end='')
    print('.>')
