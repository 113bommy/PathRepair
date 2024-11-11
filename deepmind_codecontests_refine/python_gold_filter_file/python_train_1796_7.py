from sys import stdin, stdout

def main():

    t = int(stdin.readline())

    for _ in range(t):
        n, k = map(int, stdin.readline().split(' '))

        if n == k:
            stdout.write('YES\n')
            stdout.write(' '.join(map(str, [1 for i in range(n)]))+'\n')
            continue
        if n < k:
            stdout.write('NO\n')
        else:
            ans = []
            # Test odd
            if (n - (k - 1)) & 1:
                for i in range(k - 1):
                    ans.append(1)
                ans.append(n - (k - 1))

                stdout.write('YES\n')
                stdout.write(' '.join(map(str, ans))+'\n')
            elif (n - 2 * (k - 1)) & 1 == 0 and (n - 2 * (k - 1)) > 0:
                for i in range(k - 1):
                    ans.append(2)
                ans.append(n - 2 * (k - 1))

                stdout.write('YES\n')
                stdout.write(' '.join(map(str, ans))+'\n')
            else:
                stdout.write('NO\n')

if __name__ == "__main__":
    main()