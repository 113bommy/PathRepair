def calculate_product(numbers):
    zeros = 0
    non_b = 1

    for x in numbers:
        if x == "0":
            print("0")
            return
        elif x == "1":
            continue
        x_list = list(x)
        if x_list[0] == "1" and all(z=="0" for z in x_list[1:]):
            zeros += (len(x_list) - 1)
        else:
            non_b = x

    print(str(non_b) + "0"*zeros)

if __name__ == "__main__":
    n = int(input())
    numbers = input().split()
    #numbers = [int(x) for x in numbers]
    calculate_product(numbers)
