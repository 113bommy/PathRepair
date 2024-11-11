# 387B-george-and-round


def read_input():
    n, m = [int(i) for i in input().split(" ")]
    a = [int(i) for i in input().split(" ")]
    b = [int(i) for i in input().split(" ")]
    return (n, m, a, b)


def remain_prob_count(n, m, a, b):
    i = 0
    j = 0
    matched_count = 0
    while j < len(b) and i < len(a):
        if a[i] <= b[j]:
            matched_count += 1
            j += 1
            i += 1
        elif a[i] < b[j]:
            i += 1
        else:
            j += 1
    return (n - matched_count)


def main():
    n, m, a, b = read_input()
    # print(len(a), len(b))
    print(remain_prob_count(n, m, a, b))


if __name__ == '__main__':
    main()
