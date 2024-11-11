from collections import Counter

n = int(input())
string = input()
c = Counter(string)
n0 = c['0'] - n // 3
n1 = c['1'] - n // 3
n2 = c['2'] - n // 3


# cnt = 0
def replace(l, a, b, num):
    if a > b:
        cnt = 0
        for i in range(n):
            if l[i] == a:
                cnt += 1
                l[i] = b
                if cnt == num:
                    break
    else:
        cnt = 0
        for i in range(n - 1, -1, -1):
            if l[i] == a:
                cnt += 1
                l[i] = b
                if cnt == num:
                    break
    return


if n0 == n1 == 0:
    print(string)
else:
    string = list(string)
    if n0 == 0:
        if n1 > 0:
            replace(string, '1', '2', n1)
        else:
            replace(string, '2', '1', n2)
    elif n1 == 0:
        if n0 > 0:
            replace(string, '0', '2', n0)
        else:
            replace(string, '2', '0', n2)
    elif n2 == 0:
        if n0 > 0:
            replace(string, '0', '1', n0)
        else:
            replace(string, '1', '0', n1)
    elif n0 > 0 and n1 > 0 and n2 < 0:
        replace(string, '0', '2', n0)
        replace(string, '1', '2', n1)
    elif n1 > 0 and n2 > 0 and n0 < 0:
        replace(string, '1', '0', n1)
        replace(string, '2', '0', n2)
    elif n2 > 0 and n0 > 0 and n1 < 0:
        replace(string, '2', '1', n2)
        replace(string, '0', '1', n0)
    elif n0 > 0 and n1 < 0 and n2 < 0:
        replace(string, '0', '2', -n2)
        replace(string, '0', '1', -n1)
    elif n1 > 0 and n2 < 0 and n0 < 0:
        replace(string, '1', '0', -n0)
        replace(string, '1', '2', -n2)
    elif n2 > 0 and n1 < 0 and n0 < 0:
        replace(string, '2', '0', -n0)
        replace(string, '2', '1', -n1)
    print(''.join(string))