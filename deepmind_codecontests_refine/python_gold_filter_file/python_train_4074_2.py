# print(100000000 // 3)
# print(33333333*7)


t = int(input())
while t:
    t -= 1
    n = int(input())

    orga = list(map(int, input().split()))
    mini = pow(10, 8) * 7 + 1

    for i in range(7):
        a = orga[i:] + orga[0:i]
        one = a.count(1)
        weeks = n//one
        days = weeks*7
        rem = n % one

        if(rem == 0):
            days -= 7
            rem = one

        # print(rem)
        # print(a)
        extday = 0
        for i in a:
            if(rem == 0):
                break

            extday += 1
            if(i == 1):
                rem -= 1

        # print("aaaaaaaa")
        # print(days, rem)
        # print(days + extday)
        mini = min(mini, days + extday)

    print(mini)

    # # print(orga)
    # a = list(map(int, orga))
    # one = a.count(1)

    # org = "".join(orga) + "".join(orga)
    # # print(org)
    # #########################
    # for i in range(one, 0, -1):
    #     # print("1 "*i)
    #     ind = org.find(str("1"*i))

    #     if(ind != -1):
    #         a = a[ind:] + a[0:ind]
    #         break

    #########################
    # print(one)
    # print(a)

    # if(a[0] != 1):
    #     first = a.index(1)
    #     a = a[first:] + a[0:first]

    # print(a)

    # weeks = n//one
    # days = weeks*7
    # rem = n % one

    # if(rem == 0):
    #     days -= 7
    #     rem = one

    # # print(rem)
    # # print(a)
    # extday = 0
    # for i in a:
    #     if(rem == 0):
    #         break

    #     extday += 1
    #     if(i == 1):
    #         rem -= 1

    # # print("aaaaaaaa")
    # # print(days, rem)
    # print(days + extday)
