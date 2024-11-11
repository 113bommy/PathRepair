for test_case in range(int(input())):
    size = int(input())
    string = input()
    left, right = 1, 1
    increasing = True
    for i in range(size - 1):
        if string[i] > string[i+1]:
            increasing = False
            break
    if increasing:
        print(string)
        continue
    for i in range(size):
        if string[i] == '1':
            left = i
            break
    for i in range(size - 1, 0, -1):
        if string[i] == '0':
            right = i
            break
    final = string[:left] + '0' + string[right + 1:]
    print(final)

