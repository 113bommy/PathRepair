
n = int(input())
s = input()
p = 0
good = [0]*(n+1)
options = [0]*(n)
for i in range(n):
    if s[i] == '(':
        p += 1
        options[i] = p
        good[i+1] = good[i]+1
    else:
        p -= 1
        options[i] = p
        good[i+1] = good[i]
options2 = list(reversed(options))

if abs(p) != 2:
    print(0)
else:
    small = min(options)
    if p == 2:
        if small >= 2:
            print(good[n])
        elif small < 0:
            print(0)
        else:
            index = -1
            while options[index] >= 2:
                index -= 1
            print(good[n]-good[index])
    elif p == -2:
        if small < -2:
            print(0)
        elif small == -2:
            x = options.index(-1)
            print(x+1-good[x+1])
