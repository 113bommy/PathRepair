def main():
    n = int(input())
    r = 0
    c = 0
    if n % 2 == 0:
        # print("n is even: ", n)
        n_2 = int(n / 2)
        if n_2 % 2 == 0:
            # print("n_2 is even: ", n_2)
            r = n
            c = n_2 + 1
        else:
            # print("n_2 is odd: ", n_2)
            r = 1
            c = n_2 + 1
        # print("r and c are: ", r, c)
        print("white")
        print("1 2")
    else:
        # print("n is odd: ", n)
        print("black")


main()
