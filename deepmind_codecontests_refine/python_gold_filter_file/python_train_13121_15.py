while True:
    n = input()
    if n == "0":
        break
    print(sum(int(x) for x in n))

