def cal(n, a, b, a1, aminus):
    for i in range(n):

        # print("i---" + str(i))
        if(a[i] < b[i]):
            if(a1 >= i or a1 == -1):
                # print("vvv")
                return False
        elif(a[i] > b[i]):
            if(aminus >= i or aminus == -1):
                return False

    return True


t = int(input())
while t:
    t -= 1
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    try:
        a1 = a.index(1)

    except ValueError:
        a1 = -1

    try:
        aminus = a.index(-1)
    except ValueError:
        aminus = -1

    # print(a1, aminus)

    val = cal(n, a, b, a1, aminus)
    if(val == True):
        # print("aaaaaaaaaaaaaaaaaaaaaaaaaaaaa")
        # print(a1, aminus)
        print("YES")
        # print("aaaaaaaaaaaaaaaaaaaaaaaaaaaaa")
    else:
        # print("aaaaaaaaaaaaaaaaaaaaaaaaaaaaa")
        # print(a1, aminus)
        print("NO")
        # print("aaaaaaaaaaaaaaaaaaaaaaaaaaaaa")
