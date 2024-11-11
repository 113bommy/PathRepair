def is_possible(x, A):
    current = {}
    length = 0
    for a in A:
        if a <= length:
            if x == 1:
                return False
            current = {k: current[k] for k in current if k < a}
            i = a - 1
            if i not in current:
                current[i] = 0
            current[i] += 1
            while i in current and current[i] >= x:
                if i == 0:
                    return False
                if (i-1) not in current:
                    current[i-1] = 0
                current[i-1] += 1
                del current[i]
                i -= 1
        length = a

    return True


def main():
    N = int(input())
    A = list(map(int, input().split()))
    left = 1
    right = N
    while left < right:
        center = (left + right) // 2
        if is_possible(center, A):
            right = center
        else:
            left = center + 1
    print(left)


if __name__ == "__main__":
    main()
