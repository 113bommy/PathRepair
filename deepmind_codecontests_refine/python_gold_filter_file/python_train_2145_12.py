def is_increasing(array: list) -> bool:
    for i in range(len(array) - 1):
        if array[i + 1] < array[i]:
            return False

    return True


def main():
    [n, k] = [int(_) for _ in input().split()]
    a = [int(_) for _ in input().split()]
    b = [int(_) for _ in input().split()]

    if len(b) > 1:
        print('Yes')
    else:
        index_zero = a.index(0)
        a1 = a[:index_zero]
        a2 = a[index_zero + 1:]
        a1_length = len(a1)
        a2_length = len(a2)

        if a1_length < 1:
            print('No' if is_increasing(a2) and b[0] < a2[0] else 'Yes')
        elif a2_length < 1:
            print('No' if is_increasing(a1) and b[0] > a1[a1_length - 1] else 'Yes')
        else:
            print('No' if is_increasing(a1) and is_increasing(a2) and a1[a1_length - 1] < b[0] < a2[0] else 'Yes')


if __name__ == '__main__':
    main()
