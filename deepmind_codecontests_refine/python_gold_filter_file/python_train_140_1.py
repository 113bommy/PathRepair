t, p = input().lower(), 'abcdefghijklmnopqrstuvwxyz|'[int(input())]
print(''.join(i.upper() if i < p else i for i in t))