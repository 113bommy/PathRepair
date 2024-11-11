while True:
    try:
        inp = list(map(int, input().split(",")))
        l = inp[0:10]
        l_all = sum(l)
        v1 = inp[10]
        v2 = inp[11]
        l_pass = l_all*v1/(v1 + v2)
        for i in range(11):
            if sum(l[:i]) >= l_pass:
                print(i)
                break
    except:
        break

