s = input()
if s in {'a1', 'a8', 'h1', 'h8'}:
    print(3)
elif s[0] in {'a', 'h'} or s[1] in {'1', '8'}:
    print(5)
else:
    print(8)
