def transfer_to_3(val):
    s = list()
    while val > 0:
        s.append(val % 3)
        val //= 3
    s = ''.join(map(str, s))
    return s[::-1]


if __name__ == "__main__":
    n = int(input())
    for i in range(0, n):
        x = int(input().strip())
        t = transfer_to_3(x)
        has_2 = False
        # print("t is {0}".format(t))
        for k, v in enumerate(t):
            if v is '2':
                if k is 0:
                    print(int('1' + '0' * len(t), 3))
                else:
                    while k > 0:
                        k -= 1
                        if t[k] is '0':
                            # print("k is {0}".format(k))
                            # print("t is {0}".format(t[0:k] + '1' + '0' * (len(t) - k)))
                            print(int(t[0:k] + '1' + '0' * (len(t) - 1 - k), 3))
                            break
                    else:
                        print(int('1' + '0' * len(t), 3))
                break
        else:
            print(int(t, 3))
