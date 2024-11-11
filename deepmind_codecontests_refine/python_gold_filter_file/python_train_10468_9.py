inp = input()
if 2 <= int(inp[1]) <= 7 and 'a' < inp[0] < 'h':
    print(8)
elif inp in ['a1', 'a8', 'h8', 'h1']:
    print(3)
else:
    print(5)