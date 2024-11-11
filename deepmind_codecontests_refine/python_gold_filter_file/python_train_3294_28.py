from sys import stdin, stdout

t = int(stdin.readline())

for i in range(t):
    n, k = map(int, stdin.readline().split())
    values = sorted(list(map(int, stdin.readline().split())))
    length = [values[0], n - values[-1] + 1]
    
    for i in range(0, k - 1):
        cnt = values[i + 1] - values[i] + 1
        
        if cnt & 1:
            length.append((cnt >> 1) + 1)
        else:
            length.append(cnt >> 1)

    stdout.write(str(max(length)) + '\n')  