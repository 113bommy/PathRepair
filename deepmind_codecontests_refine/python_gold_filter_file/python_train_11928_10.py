
import sys
from numbers import Integral
#TODO: finish



div2_max_rate = 1899


def main():
    n = int(sys.stdin.readline().strip())

    c_list, d_list = [], []

    rates = []

    for i in range(n):
        c, d = [int(s) for s in sys.stdin.readline().split()]

        if i == 0:
            rates.append(0)
        else:
            rates.append(rates[-1] + c_list[-1])

        c_list.append(c)
        d_list.append(d)

    rates.append(rates[-1] + c_list[-1])

    # check if everything is OK
    for i in range(n - 1):
        c = c_list[i]
        d = d_list[i]

        d_n = d_list[i + 1]

        impossible = False
        if c * (d_n - d) > 0:
            impossible = True

        if c == 0 and d_n != d:
            impossible = True

        if impossible:
            print("Impossible")
            return




    # Find the maximum allowed shift
    mx_rate = None
    for r, d in zip(rates, d_list):
        if d == 2:
            if mx_rate is None:
                mx_rate = r
            else:
                mx_rate = max(mx_rate, r)

    if mx_rate is None:
        print("Infinity")
        return

    d = div2_max_rate - mx_rate

    rates = [r + d for r in rates]

    impossible = False
    for r, d in zip(rates, d_list):
        if r > div2_max_rate and d == 2:
            impossible = True

        if r <= div2_max_rate and d == 1:
            impossible = True

        if impossible:
            print("Impossible")
            return



    print(rates[-1])




if __name__ == '__main__':
    main()
