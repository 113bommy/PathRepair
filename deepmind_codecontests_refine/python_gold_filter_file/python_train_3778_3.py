from sys import stdin, gettrace

if gettrace():
    inputi = input
else:
    def input():
        return next(stdin)[:-1]


    def inputi():
        return stdin.buffer.readline()


def solve():
    p, q = map(int, inputi().split())
    if p%q != 0:
        print(p)
        return
    qf = {}
    qr = q
    i = 2
    while i*i <= qr:
        while qr%i == 0:
            qf[i] = qf.get(i, 0) + 1
            qr //= i
        i+=1
    if qr != 1:
        qf[qr] = 1
    pf = {}
    pr = p
    for f in qf.keys():
        pf[f] = 0
        while pr%f == 0:
            pf[f] += 1
            pr //= f
    best = 0
    for f in qf.keys():
        best = max(p//(f**(pf[f] -qf[f]+1)), best)
    print(best)





def main():
    t = int(inputi())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
