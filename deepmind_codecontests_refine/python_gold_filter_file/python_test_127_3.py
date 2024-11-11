for _ in range(int(input())):
    givenstr = sorted(input())
    banned = input()
    res = ""
    count = 0
    for i in givenstr:
        if i == banned[count]:
            count += 1
        if count == 3:
            break
    if count == 3:
        cnt = givenstr.count(banned[-1])
        start = givenstr.index(banned[-1])
        res += "".join(givenstr[:givenstr.index(banned[1])]) + "".join(givenstr[start:start + cnt]) + "".join(
            givenstr[givenstr.index(banned[1]):start]) + "".join(givenstr[start + cnt:])
        print(res)
    else:
        print(*givenstr, sep="")
