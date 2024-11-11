import sys

input = sys.stdin.readline


def main():
    U, V = [int(x) for x in input().split()]

    if U > V:
        print(-1)
        return

    if V == 0:
        print(0)
        return

    if U == V:
        print(1)
        print(U)
        return

    if abs(U - V) % 2 != 0:
        print(-1)
        return

    if ((V - U) // 2) & U == 0:
        print(2)
        print((V - U) // 2, U + (V - U) // 2)
    else:
        print(3)
        print((V - U) // 2, (V - U) // 2, U)


if __name__ == '__main__':
    main()
