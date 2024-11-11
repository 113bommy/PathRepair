def calculate(test):
    count = 0
    a, b = max(test), min(test)
    while a != 0 and b != 0:
        count += a // b
        a, b = b, a % b
    print(count)


for i in range(int(input())):
    iSet = list(map(int, input().split()))
    calculate(iSet)