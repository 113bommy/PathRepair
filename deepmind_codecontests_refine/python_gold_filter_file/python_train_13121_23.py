while True:
    x = input()
    if x == "0":
        break
    print(sum([int(_) for _ in list(x)]))


