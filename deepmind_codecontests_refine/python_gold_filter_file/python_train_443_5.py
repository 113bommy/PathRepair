from sys import stdin, stdout
readline, writeline = stdin.readline, stdout.write


def lint():
    return list(mint())


def mint():
    return map(int, readline().strip().split())


def iint():
    return int(readline().strip())


for _ in range(iint()):
    d, k = mint()
    n = d // (k * (2 ** 0.5))
    l = k * n

    if ((d**2 - l**2) ** 0.5) - l >= k:
        ans = "Ashish"
    else:
        ans = "Utkarsh"
    writeline("{}\n".format(ans))
