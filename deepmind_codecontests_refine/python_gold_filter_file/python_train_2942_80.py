# suppose he has 10 sticks

# then the sticks are of length 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 -
# our task is to create max sticks of equal length
# 10 + 1 = 9 + 2 = 8 + 3 = 4 + 5 = 5 + 6 = 11
# so now there are 5 sticks of length 11 - (10, 1), (9, 2), (8, 3), (7, 4), (5, 6)
#

# but if it was 11 then there would be 10 pairs and one would be left out
#


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        if n == 1 or n == 2:
            print(1)
        else:
            if n % 2 == 1:
                print((n - 1) // 2 + 1)
            else:
                print(n // 2)



