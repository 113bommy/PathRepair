while True:
    data = input()
    if data == '0':
        break

    print(sum([int(i) for i in data]))