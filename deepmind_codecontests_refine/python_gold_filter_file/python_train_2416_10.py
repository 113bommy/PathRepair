def solve():
    n = int(input())
    pins = []
    letters = []
    for j in range(n):
        pin = input()
        pins.append(list(pin))
        letters.append(pin[0])
    res = 0
    for a in range(len(pins)):
        if pins.count(pins[a]) >= 2:
            for j in range(0, 10):
                if str(j) not in letters:
                    letters.append(str(j))
                    pins[a][0] = str(j)
                    res += 1
                    break
    print(res)
    for pin in pins:
        print(*pin, sep='')


t = int(input())
for i in range(t):
    solve()