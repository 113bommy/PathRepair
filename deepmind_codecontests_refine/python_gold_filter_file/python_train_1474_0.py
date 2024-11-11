def main():
    n = int(input())
    a = list(map(int, input().split()))
    result = [0] * n
    last_increasing = -1
    last_decreasing = 200001

    for i, x in enumerate(a):
        if i == n - 1:
            if x < last_decreasing:
                result[i] = 1
            elif x <= last_increasing:
                print('NO')
                return
        else:
            if last_increasing >= x >= last_decreasing:
                print('NO')
                return
            if x > last_increasing and x >= last_decreasing:
                last_increasing = x
            if x <= last_increasing and x < last_decreasing:
                last_decreasing = x
                result[i] = 1
            if last_increasing < x < last_decreasing:
                if a[i + 1] > x:
                    last_increasing = x
                else:
                    last_decreasing = x
                    result[i] = 1

    print('YES')
    print(' '.join(map(str, result)))


if __name__ == '__main__':
    main()
