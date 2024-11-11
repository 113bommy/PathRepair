ab = int(input())
for s in range(ab):
    temp = input()
    rem = 0
    for i in temp:
        if i == 'B' and rem != 0:
            rem = rem - 1
        else:
            rem = rem + 1
    print(rem)
