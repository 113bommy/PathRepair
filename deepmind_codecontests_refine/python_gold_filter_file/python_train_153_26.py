from sys import stdin
count = 0
l = 0
while True:
    s = stdin.readline().strip()
    if len(s) <= 1:
        break
    if s[0] == '+':
        count += 1
    elif s[0] == '-':
        count -= 1
    else:
        l += count*len(s[s.index(':')+1:])
print(l)