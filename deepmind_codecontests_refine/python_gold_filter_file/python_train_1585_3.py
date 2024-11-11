t = int(input())
for i in range(t):
    n = int(input())
    s = str(input())
    s = list(s)
    while len(s) > 0 and int(s[-1]) % 2 == 0:
        s.pop(-1)
    if len(s) == 0:
        print(-1)
    else:
        sum_x = 0
        for elem in s:
            sum_x += int(elem)
        if sum_x % 2 == 0:
            print(''.join(s))
        else:
            if len(s) > 2:
                flag = -1
                for j in range(len(s) - 1):
                    if int(s[j]) % 2 == 1:
                        flag = j
                if flag == -1:
                    print(-1)
                else:
                    temp = ''.join(s[:flag]) + ''.join(s[flag+1:])
                    if temp[0] == '0':
                        print(-1)
                    else:
                        print(temp)
            else:
                print(-1)
