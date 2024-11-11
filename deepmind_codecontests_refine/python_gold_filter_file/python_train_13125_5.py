while True:
    x = input()
    if x == '0':
        break
    print(sum(int(c) for c in x))