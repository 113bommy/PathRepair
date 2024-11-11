case = int(input())
for caseNum in range(0, case):
    n = int(input())
    numberList = [int(x) for x in input().split()]
    if numberList[0] + numberList[1] > numberList[n-1]:
        print(-1)
    else:
        print(1, 2, n)
