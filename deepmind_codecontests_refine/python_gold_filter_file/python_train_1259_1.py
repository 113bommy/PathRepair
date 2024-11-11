for _ in range(int(input())):
    n = int(input())
    s = input()
    res = True
    for i in range(n // 2):
        if(ord(s[i]) == 'a' and ord(s[-1 - i]) == 'z'):
            res = False
            break
        else:
            m = abs(ord(s[i]) - ord(s[-1 - i]))
            if(m != 2 and m != 0):
                res = False
                break
    print("YES" if res else "NO")
