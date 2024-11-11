USE_STDIO = False

import collections

if not USE_STDIO:
    try: import mypc
    except: pass

def main():
    n,  = map(int, input().split(' '))
    s = list(map(int, input().split(' ')))
    cnts = collections.Counter(s)
    num1, num2, num3 = 0, 0, 0
    for c in cnts.values():
        if c == 1: num1 += 1
        elif c == 2: num2 += 1
        else: num3 += 1
    if num1 % 2 == 1 and num3 == 0:
        print('NO')
        return
    print('YES')
    ans = []
    A, B, C = 0, 0, 0
    if num1 % 2 == 0:
        C += 1
    for x in s:
        if cnts[x] == 1:
            if A == B:
                ans.append('A')
                A += 1
            else:
                ans.append('B')
                B += 1
        elif cnts[x] >= 3 and C == 0:
            ans.append('B')
            C += 1
        else:
            ans.append('A')
    print(''.join(ans))

if __name__ == '__main__':
    main()



