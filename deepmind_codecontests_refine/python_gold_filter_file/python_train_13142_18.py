from sys import stdin

input = stdin.readline


def main():
    test = int(input())

    for t in range(test):
        l = [int(i) for i in input().split(" ")]
        a = l[0]
        k = l[1]
        flag = True

        while k > 1:
            m1 = 9
            m2 = 0
            b = a

            while b > 0:
                c = b % 10

                if c == 0:
                    flag = False
                    break

                m1 = min(m1, c)
                m2 = max(m2, c)
                b = b // 10

            k -= 1

            if flag:
                a += m2 * m1
            else:
                break
        print(a)


main()
