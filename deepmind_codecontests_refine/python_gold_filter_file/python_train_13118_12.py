n = int(input())
d = {}
for i in range(n):
    cmd = input()
    if cmd[0] == 'i':
        d[cmd[7:]] = 0
    else:
        print('yes' if cmd[5:] in d else 'no')