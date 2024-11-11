while True:
    s = input()
    if s == "0":
        break
    print(sum([int(c) for c in s]))

