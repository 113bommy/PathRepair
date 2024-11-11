from collections import defaultdict


def arrinp():
    return [*map(int, input().split(' '))]


def mulinp():
    return map(int, input().split(' '))


def intinp():
    return int(input())


def solution():
    n = intinp()
    a = arrinp()
    if len(set(a)) == 1:
        a = [1]*n
        print(1)
        print(*a)
        return
    arr = [1 if x % 2 == 0 else 2 for x in range(n)]
    if n % 2 != 0 and a[0] != a[-1]:
        for j in range(1, n):
            if a[j] == a[j-1]:
                arr[j] = arr[j-1]
                for k in range(j+1, n):
                    arr[k] = 3-arr[k-1]
                break
        else:
            arr[-1] = 3
    print(max(arr))
    print(*arr)


testcases = 1
testcases = int(input())
for _ in range(testcases):
    solution()
