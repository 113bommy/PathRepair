# https://codeforces.com/problemset/problem/710/A

s = input()

if s[0] in {'a', 'h'}:
    if s[1] in {'8', '1'}:
        print(3)
    else:
        print(5)
else:
    if s[1] in {'8', '1'}:
        print(5)
    else:
        print(8)