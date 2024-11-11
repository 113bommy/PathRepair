t = int(input())
for i in range(t):
    n, k, a, b = map(int, input().split())
    if n % 3 != 0:
        print("no")
    else:
        for i in range(2):
            for j in range(2):
                flagf = False
                if i == 0:
                    a1 = a
                else:
                    a1 = -a
                if j == 0:
                    b1 = b
                else:
                    b1 = -b

                t2 = (k - a1 + b1)/3
                t1 = a1 + t2
                t3 = t2 - b1
                # print(t1, t2, t3)

                flag1 = False
                flag2 = False
                # valores válidos
                if (k-a1+b1) % 3 == 0 and t1 >= 0 and t2 >= 0 and t3 >= 0:
                    if t1 <= n/3 and t2 <= n/3 and t3 <= n/3:
                        if i == 0 and t1 >= t2:
                            flag1 = True
                        elif i == 1 and t1 < t2:
                            flag1 = True
                        if j == 0 and t2 >= t3:
                            flag2 = True
                        elif j == 1 and t2 < t3:
                            flag2 = True

                if flag1 and flag2:
                    if t1 == t2 and t2 == t3 and (n-k) % 3 == 0:
                        flagf = True
                        break
                    else:
                        v = [t1, t2, t3]
                        v = sorted(v)
                        faltam = n-k
                        faltam -= v[2] - v[1]
                        faltam -= v[2] - v[0]
                        if faltam < 0:
                            break
                        elif faltam == 0 or faltam %3 == 0:
                            flagf = True
                            break


            if flagf:
                print("yes")
                break
        else:
            print("no")


# 3 1 1 0
