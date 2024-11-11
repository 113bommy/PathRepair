n = int(input())
numbers = list(map(int, input().split()))

def main() :
    x = numbers[n - 1]
    i = 0
    for j in range(n) :
        if numbers[j] <= x :
            numbers[i], numbers[j] = numbers[j], numbers[i]
            i += 1

    [print(numbers[j] if j != i - 1 else '['+str(numbers[j])+']', end = ' ' if j != n - 1 else '\n') for j in range(n)]

if __name__ == '__main__':
    main()

