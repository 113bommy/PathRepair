for _ in range(int(input())):
    s = input()
    if set(s) == {'0'}:
        print('0')
        continue
    s = list(s)
    st = 0
    en = 0
    for i in range(len(s)):
        if s[i] == '1':
            st = i
            break
    for i in range(len(s)):
        if s[len(s) - i - 1] == '1':
            en = len(s) - i - 1
            break
    print(s[st: en + 1].count('0'))