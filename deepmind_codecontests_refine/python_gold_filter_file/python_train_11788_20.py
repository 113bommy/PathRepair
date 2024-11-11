t = int(input())

for i in range(t):
    s = input()
    s = list(s)

    if len(s) == 1 or len(s) == s.count('0'):
        print(0)

    else:
        while s[0] == '0' or s[-1] == '0':
            if s[0] == '0':
                s.pop(0)
            if s[-1] == '0':
                s.pop(-1)
            
        c = 0
        for i in s:
            if i == '0':
                c += 1

        print(c)