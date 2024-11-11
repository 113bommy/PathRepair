# print("Input number of test cases")
t = int(input())
for i in range(t):
    # print("Input n")
    n = int(input())

    if n<4:
        print(4-n)
    elif n%2==0:
        print(0)
    else:
        print(1)
