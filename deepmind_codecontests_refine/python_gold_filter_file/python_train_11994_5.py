n = int(input())
for _ in range(n):
    p = {'a', 'b', 'c'}
    s = list(input())
    if len(s) == 1 and s[0] == '?':
        print('a')
        continue
    for i in range(len(s)):
        if i >= 1:
            if s[i] == s[i-1] and s[i] != '?':
                print(-1)
                break
        if s[i] == '?':
            if i == 0 and s[i+1] == 'a':
                s[i] = 'b'
            elif i == 0 and s[i+1] == 'b':
                s[i] = 'c'
            elif i == 0 and s[i+1] == 'c':
                s[i] = 'a'
            if i == len(s) - 1 and s[i - 1] == 'a':
                s[i] = 'b'
            elif i == len(s) - 1 and s[i - 1] == 'b':
                s[i] = 'c'
            elif i == len(s) - 1 and s[i - 1] == 'c':
                s[i] = 'a'
            else:
                p1 = {s[i-1], s[i+1]}
                choice = ''.join(p - p1)
                s[i] = choice[0]
        if i == len(s) - 1:
            print(''.join(s))