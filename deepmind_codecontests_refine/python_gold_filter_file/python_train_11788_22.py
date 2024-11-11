n = int(input())

for i in range(0, n):
    s = input()
    flag = False
    left = 0
    for j in range(0, len(s)):
        if flag and s[j] == '0':
            left += 1
        if s[j] == '1':
            flag = True
    right = 0
    for j in range(len(s) - 1, -1, -1):
        if s[j] == '1':
            break
        right += 1

    if left - right < 0:
        print(0)
    else:
        print(left - right)
