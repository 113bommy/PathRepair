while True:
    s = input()
    if s == '.':break
    while True:
        if s.find('+') == -1 and s.find('-') == -1:
            index = s.rfind('[')
            if index == -1:break
            e = s.find(']', index)
            s = s[:index] + s[index + 1:e][::-1] + s[e + 1:]
        else:
            index = s.find('+')
            if index == -1:
                index = s.find('-')
            if s.find('-') != -1:
                index = min(index, s.find('-'))
            e = index
            f = 0
            while s[e] == '+' or s[e] == '-':
                f += [-1, 1][s[e] == '+']
                e += 1
            r = s[e]
            if r != '?':
                r = chr((ord(r) - ord('A') + f) % 26 + ord('A'))
            s = s[:index] + r + s[e + 1:]
    print(s.replace('?', 'A'))
