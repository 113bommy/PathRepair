def main():
    print('\n'.join(('O-|-OOOO',
                     'O-|O-OOO',
                     'O-|OO-OO',
                     'O-|OOO-O',
                     'O-|OOOO-',
                     '-O|-OOOO',
                     '-O|O-OOO',
                     '-O|OO-OO',
                     '-O|OOO-O',
                     '-O|OOOO-')[_] for _ in reversed(list(map(int, input())))))


if __name__ == '__main__':
    main()