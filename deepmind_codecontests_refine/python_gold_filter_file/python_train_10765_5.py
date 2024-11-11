def main(n=input()):
    for i, a in enumerate(reversed(list(map(int,n)))):
        x = ''
        if a >= 5:
            x += '-O'
        else:
            x += 'O-'
        x += '|'
        y = 4
        for i in range(a % 5):
            x += 'O'
            y -= 1
        x += '-'
        for i in range(y):
            x += 'O'

        print(x)
main()
