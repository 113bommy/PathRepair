while True:
    n = input()
    if n == '0':
        break
    print(sum(int(i) for i in n))