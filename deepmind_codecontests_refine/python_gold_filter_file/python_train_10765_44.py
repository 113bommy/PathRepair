ns = input()

for i in range(len(ns)-1,-1,-1):
    if int(ns[i]) < 5:
        print('O-|', end = '')
    else:
        print('-O|', end = '')

    c = int(ns[i])%5
    for j in range(5):
        if j == c:
            print('-', end = '')
        else:
            print('O', end = '')
    print()
