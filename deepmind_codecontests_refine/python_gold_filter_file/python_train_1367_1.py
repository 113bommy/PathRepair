def read(type = 1):
    if type:
        file = open("input.dat", "r")
        n = int(file.readline())
        a = list(map(int, file.readline().split()))
        b = file.readline()
        file.close()
    else:
        n = int(input().strip())
        a = list(map(int, input().strip().split()))
        b = input().strip()
    return n, a, b


def solve():
    sol = 0
    e = 0
    big = 0
    g = 0
    for i in range(n):
        if b[i] == "W":
            big = 1
            sol += 3 * a[i]
            e += a[i]
        if b[i] == "G":
            sol += 5 * a[i]
            e += a[i]
            g += 2*a[i]
        if b[i] == "L":
            sol += a[i]
            e -= a[i]
            if e < 0:
                if big:
                    sol -= 3 * e
                else:
                    sol -= 5 * e
                e = 0
        g = min(g, e)
    if e:
        sol -= 2*g
        sol -= (e-g)
    return int(sol)


n, a, b = read(0)
sol = solve()
print(sol)