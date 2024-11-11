import math
def main():
    # both cup and medel not in same rack
    # not > 5 cup
    # not > 10 medel

    cup = sum(list(map(int, input().split())))
    medel = sum(list(map(int, input().split())))
    rack = int(input())

    cup_rack = math.ceil(cup / 5.0)
    medel_rack = math.ceil(medel / 10.0)

    if cup_rack + medel_rack <= rack:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()