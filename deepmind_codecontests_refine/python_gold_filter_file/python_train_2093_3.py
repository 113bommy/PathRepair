n = int(input())
s = input()
if s == '0' * n:
    print('YES')
else:
    sum1 = 0
    smth = False
    for i in range(n):
        sum1 += int(s[i])
    for i in range(2, sum1 + 1):
        if sum1 % i == 0:
            x = 0
            x += sum1
            x = x // i
            u1 = 0
            now = 0
            flag = True
            while u1 < n:
                if now < x:
                    now += int(s[u1])
                    u1 += 1
                elif now == x:
                    now = 0
                else:
                    flag = False
                    break
                if now > x:
                    flag = False
                    break
            if flag and not smth:
                print('YES')
                smth = True
    if not smth:
        print('NO')