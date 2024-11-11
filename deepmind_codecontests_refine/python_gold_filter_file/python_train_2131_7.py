i = int(input())
j = i + 1


def check_8(i):
    s = str(i)
    for c in s:
        if c == '8':
            return True
    return False


while not check_8(j):
    j += 1
print(j - i)
