import math


def check(mx1, mx2):
    for i in range(2, int(math.sqrt(mx1)) + 1):
        if mx1 % i == 0 and (mx2 % i == 0 or mx2 % (mx1 // i) == 0):
            return False
    if mx2 % mx1 == 0:
        return False
    return True


def main():
    x = int(input())
    mx11, mx21 = 1, x
    for i in range(2, int(math.sqrt(x)) + 3):
        if x % i == 0:
            mx1, mx2 = i, x // i
            if check(mx1, mx2):
                mx11, mx21 = mx1, mx2
    print(mx11, mx21)


if __name__ == "__main__":
    t = 1
    for i in range(t):
        main()