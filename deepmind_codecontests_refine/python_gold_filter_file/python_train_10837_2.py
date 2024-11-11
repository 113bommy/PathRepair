# row <= 5 col <= 20
string = list(input())
len_string = len(string)
if len_string <= 20:
    print(1, len_string)
    print("".join(string))
    quit(0)

if 20 < len_string < 41:
    if len_string % 2 != 0:
        string.append("*")
        len_string += 1
    print(2, len_string // 2)
    print("".join(string[:len_string // 2]))
    print("".join(string[len_string // 2:]))
    quit(0)

if 40 < len_string < 61:
    if len_string % 3 == 2:
        len_string += 1
        string.append("*")
    elif len_string % 3 == 1:
        string = ["*"] + string
        string.append("*")
        len_string += 2
    print(3, len_string // 3)
    print("".join(string[:len_string // 3]))
    print("".join(string[len_string // 3:2 * len_string // 3]))
    print("".join(string[2 * len_string // 3:]))
    quit(0)

if 60 < len_string < 81:
    if len_string % 4 == 3:
        len_string += 1
        string.append("*")
    elif len_string % 4 == 2:
        string = ["*"] + string
        string.append("*")
        len_string += 2
    elif len_string % 4 == 1:
        len_string += 3
        string = ["*"] + string
        string.append("*")
        string.insert(len_string // 4 + 2, "*")
    print(4, len_string // 4)
    print("".join(string[:len_string // 4]))
    print("".join(string[len_string // 4:2 * len_string // 4]))
    print("".join(string[2 * len_string // 4: 3 * len_string // 4]))
    print("".join(string[3 * len_string // 4:]))
    quit(0)

if 80 < len_string < 101:
    if len_string % 5 == 4:
        len_string += 1
        string.append("*")
    elif len_string % 5 == 3:
        string = ["*"] + string
        string.append("*")
        len_string += 2
    elif len_string % 5 == 2:
        len_string += 3
        string = ["*"] + string
        string.append("*")
        string.insert(len_string // 5 + 2, "*")
    elif len_string % 5 == 1:
        len_string += 4
        string = ["*"] + string
        string.append("*")
        string.insert(len_string // 5 + 2, "*")
        string.insert(2 * len_string // 5 + 2, "*")
    print(5, len_string // 5)
    print("".join(string[:len_string // 5]))
    print("".join(string[len_string // 5:2 * len_string // 5]))
    print("".join(string[2 * len_string // 5: 3 * len_string // 5]))
    print("".join(string[3 * len_string // 5: 4 * len_string // 5]))
    print("".join(string[4 * len_string // 5:]))
    quit(0)
