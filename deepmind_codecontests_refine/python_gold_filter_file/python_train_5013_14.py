# https://codeforces.com/problemset/problem/1156/B

def position(a):
    if a == 'a':
        return 1
    if a == 'b':
        return 2
    if a == 'c':
        return 3
    if a == 'd':
        return 4
    if a == 'e':
        return 5
    if a == 'f':
        return 6
    if a == 'g':
        return 7
    if a == 'h':
        return 8
    if a == 'i':
        return 9
    if a == 'j':
        return 10
    if a == 'k':
        return 11
    if a == 'l':
        return 12
    if a == 'm':
        return 13
    if a == 'n':
        return 14
    if a == 'o':
        return 15
    if a == 'p':
        return 16
    if a == 'q':
        return 17
    if a == 'r':
        return 18
    if a == 's':
        return 19
    if a == 't':
        return 20
    if a == 'u':
        return 21
    if a == 'v':
        return 22
    if a == 'w':
        return 23
    if a == 'x':
        return 24
    if a == 'y':
        return 25
    if a == 'z':
        return 26

trials = int(input())

for i in range(trials):
    sequence = list(input())
    odds = []
    evens = []
    impossible = ''

    # Make list of even and odd letters

    for j in sequence:
        if j in ['a', 'c', 'e', 'g', 'i', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y']:
            odds.append(j)
        if j in ['b', 'd', 'f', 'h', 'j', 'l', 'n', 'p', 'r', 't', 'v', 'x', 'z']:
            evens.append(j)

    # Sort ascending

    odds_up = sorted(odds)
    evens_up = sorted(evens)

    final_1 = odds_up + evens_up
    final_2 = evens_up + odds_up

    for j in range(len(final_1) - 1):
        if abs(position(final_1[j]) - position(final_1[j + 1])) == 1:
            impossible = 'True'
    if impossible == '':
        print(''.join(final_1))

    # If that didn't work, we try the opposite ordering

    else:
        impossible = ''
        for j in range(len(final_2) - 1):
            if abs(position(final_2[j]) - position(final_2[j + 1])) == 1:
                impossible = 'True'
        if impossible == '':
            print(''.join(final_2))
        else:
            print('No answer')






