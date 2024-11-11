def compute_n_shifts(l, main_shift, shift):
    d = shift - main_shift
    if d >= 0:
        return d
    else:
        return l + d


def main():
    n = int(input())
    strings = []
    for i in range(n):
        strings.append(input())

    shifts = []
    test_string = strings[0]
    l = len(test_string)
    for s in strings:
        shifts_i = []
        for shift in range(l):
            t = s[shift:] + s[:shift]
            if t == test_string:
                shifts_i.append(shift)

        if not shifts_i:
            return -1

        shifts.append(shifts_i)

    answer = l * n + 1
    for main_shift in range(l):
        n_shifts = 0
        for shifts_i in shifts:
            n_shifts += min(compute_n_shifts(l, main_shift, x)
                            for x in shifts_i)
        answer = min(answer, n_shifts)

    return answer


if __name__ == '__main__':
    # import sys
    # sys.stdin = open("B.txt", "r")
    answer = main()
    print(answer)
