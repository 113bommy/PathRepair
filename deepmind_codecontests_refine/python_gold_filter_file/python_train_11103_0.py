length = int(input())

line = input().strip()

idx = 0
count = 0

while idx < len(line):
    if idx < len(line) - 1 and line[idx] == 'R' and line[idx+1] == 'U':
        idx += 1

    elif idx < len(line) - 1 and line[idx] == 'U' and line[idx+1] == 'R':
        idx += 1

    count += 1
    idx += 1

print(count)
