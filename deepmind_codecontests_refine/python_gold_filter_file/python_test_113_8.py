def solve_test():
    x1, p1 = map(int, input().split(" "))
    x2, p2 = map(int, input().split(" "))

    while x1 % 10 == 0:
        x1 //= 10
        p1 += 1
    while x2 % 10 == 0:
        x2 //= 10
        p2 += 1
    # x1 0 * p1 compare to x2 0 * p2
    digits1 = len(str(x1))
    digits2 = len(str(x2))
    if digits1 + p1 < digits2 + p2:
        return "<"
    elif digits1 + p1 > digits2 + p2:
        return ">"
    else:
        # pad number 1 with 0
        if digits1 < digits2:
            x1 = x1 * (10 ** (digits2 - digits1))
        else:
            x2 = x2 * (10 ** (digits1 - digits2))
        if x1 > x2:
            return ">"
        elif x1 < x2:
            return "<"
        return "="


def main():
    tests = int(input())
    for _ in range(tests):
        answer = solve_test()
        print(answer)


if __name__ == "__main__":
    main()
