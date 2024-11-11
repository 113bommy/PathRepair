def check(x):
    y = {}
    for i in range(97, 123):
        if x.count(chr(i)) == 0:
            return 'NO'
    return 'YES'

n = input()
x = input()
x = x.lower()
print(check(x))