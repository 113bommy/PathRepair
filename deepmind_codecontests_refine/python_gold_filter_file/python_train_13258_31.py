import sys

def main():
    k, q = map(int, sys.stdin.readline().split())
    flag = False
    ans = {}
    for i in range(q):
        d, b = map(int, sys.stdin.readline().split())
        ans[(d, i)] = b

    for i in sorted(ans):
        if k > i[0]:
            k+=ans[i]
            flag = True

        else:
            flag = False

    if flag:
        sys.stdout.write('YES')
    else:
        sys.stdout.write('NO')

if __name__ == '__main__':
    main()