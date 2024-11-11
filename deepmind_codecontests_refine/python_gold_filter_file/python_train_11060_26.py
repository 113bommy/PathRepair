from sys import stdin, stdout

read = stdin.readline
write = stdout.write

for _ in range(int(read())):
    n = int(read())
    
    if (n / 2) % 2 == 1:
        write("NO" + '\n')
    else:
        write("YES" + '\n')
        for i in range(2, n + 1, 2):
            write(str(i) + ' ')

        for i in range(1, n - 2, 2):
            write(str(i) + ' ')

        write(str(n + n // 2 - 1) + '\n')

