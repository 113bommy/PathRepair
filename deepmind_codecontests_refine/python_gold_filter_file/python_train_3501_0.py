

def apply(smstr, start, end, letter_fr, letter_to):
    begin = smstr[:start - 1]
    finish = smstr[end:]
    to_edit = smstr[start - 1:end]
    if start == end:
    	to_edit = smstr[start -1]
    return "{}{}{}".format(begin, to_edit.replace(letter_fr, letter_to),
                           finish)


def main():
    buff = input().split()
    n, m = int(buff[0]), int(buff[1])
    n += 1
    smstr = input()
    commands = []
    for x in range(m):
        buff = input().split()
        commands.append((int(buff[0]), int(buff[1]), buff[2], buff[3]))

    for x in commands:
        smstr = apply(smstr, *x)
        # print(smstr)

    return smstr


if __name__ == "__main__":
    print(main())
