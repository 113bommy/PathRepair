def inp():
    return map(int, input().split())


def arr_enu():
    return [[i+1, int(x)] for i, x in enumerate(input().split())]

def get_col(arr, i):
    return [row[i] for row in arr]

for i in range(int(input())):
    n, m = inp()
    a = arr_enu()

    if (m < n or n==2):
        print(-1)
    else:
        a.sort(key=lambda x:x[1])
        print(sum(get_col(a,1)) * 2)

        for j in range(n):
            if (j == n - 1):
                print(a[j][0], a[0][0])
            else:
                print(a[j][0], a[j + 1][0])
