ans = 0
n = 0
while True:
    try:
        line = input()
        #print(line)
    except:
        break
    if line[0] == '+':
        n += 1
    elif line[0] == '-':
        n -= 1
    else:
        ans += len(line.split(':')[-1])*n
print(ans)
