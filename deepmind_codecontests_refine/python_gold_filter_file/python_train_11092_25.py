def main():
    n = int(input())
    directions = input()
    x = [int(y) for y in input().split()]

    last_r = -1
    res = -1
    for i in range(0, n):
        if directions[i] == 'L':
            if last_r != -1:
                res = (res >= 0 and min(res, (x[i] - x[last_r]) // 2)) or (x[i] - x[last_r]) // 2
        else:
            last_r = i
    print(res)

main()