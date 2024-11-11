if __name__ == "__main__":
    n = int(input())

    if n == 12:
        print("YES")
        exit()

    first_digit = n % 10
    second_digit = int(n / 10)

    if first_digit == 1 or first_digit == 7 or first_digit == 9 or second_digit == 1 or second_digit == 2 or second_digit == 7 or second_digit == 9:
        print("NO")
    else:
        print("YES")
