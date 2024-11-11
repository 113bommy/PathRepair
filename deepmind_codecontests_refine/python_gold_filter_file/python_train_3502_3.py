n, m = input().split()
n = int(n)
m = int(m)
names = dict()
commands = [0] * m
for i in range(n):
    name, ip = input().split()
    names[ip] = name
for i in range(m):
    commands[i] = input()
for command in commands:
    cmd, ip = command.strip(';').split()
    print(cmd + ' ' + ip + '; #' + names[ip])
