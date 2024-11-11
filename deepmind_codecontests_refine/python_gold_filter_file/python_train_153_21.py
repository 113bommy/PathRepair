from sys import stdin
active = traffic = 0
for line in stdin:
    active += line[0] == '+'
    active -= line[0] == '-'
    if ':' in line:
        traffic += active * (len(line) - line.find(':') - 2)
print(traffic)