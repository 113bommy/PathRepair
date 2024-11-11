n0 = input()
s = input()

def counter(s):
    c = 0
    for i, n in enumerate(s):
        if not int(n) % 2:
            c += i + 1
    return c

print(counter(s))