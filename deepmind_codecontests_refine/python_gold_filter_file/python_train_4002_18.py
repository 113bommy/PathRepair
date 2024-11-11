p = input()

if len(p) >= 5:
    if p != p.upper():
        if p != p.lower():
            for c in p:
                if c in '1 2 3 4 5 6 7 8 9 0'.split():
                    print('Correct')
                    exit(0)
print("Too weak")