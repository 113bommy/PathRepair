def read_string_input():
    return input()


def is_valid(string):
    check_list = ["H", "Q", "9"]
    for char in string:
        if char in check_list:
            return True
    return False


if __name__ == "__main__":
    string_input = read_string_input()
    if is_valid(string_input):
        print("YES")
        exit(0)
    print("NO")
