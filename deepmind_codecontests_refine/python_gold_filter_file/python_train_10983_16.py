string = input()

odd_count = len([x for x in string if x.islower()])

if odd_count >= len(string) / 2:
    print(string.lower())
else:
    print(string.upper())