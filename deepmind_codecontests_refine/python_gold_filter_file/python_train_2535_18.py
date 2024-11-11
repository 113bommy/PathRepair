x = int(input())

def solve(x):
    if x == 1:
        print(1)
    elif x == 2:
        print("2 1")
    else:

        y = [z for z in range(1, x)]

        print(x, *y)




solve(x)