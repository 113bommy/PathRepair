from sys import stdin


def input():
    return stdin.readline()[:-1]


def intput():
    return int(input())


def sinput():
    return input().split()


def intsput():
    return map(int, sinput())


debugging = False
def dprint(*args):
    if debugging:
        print(*args)
    else:
        pass



# Code

t = intput()
for _ in range(t):
    n = intput()
    a = list(intsput())
    places = [0] * 70
    for x in a:
        br = bin(x)[2:][::-1]
        for i in range(len(br)):
            if br[i] == '1':
                places[i] += 1

    b1 = 2 ** 54
    for i in range(54):
        if places[i] % 2:
            b1 += 2 ** i
    b2seed = 2 ** 55 - sum(a) - b1
    b2seed = bin(b2seed)[2:][::-1]
    b2 = [''] * 100
    for i in range(len(b2seed)):
        if b2seed[i] == '1':
            b2[i - 1] = '1'
        else:
            b2[i - 1] = '0'
    b2 = int(''.join(b2)[::-1], 2)
    print(3)
    print(b1, b2, b2)
