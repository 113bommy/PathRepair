n, s, cnt, up, down, left, right = int(input()), input(),0, 0, 0, 0, 0
for i in range(n):
    if s[i] == "U" and down == 0:
        up = 1
    elif s[i] == "U" and down == 1:
        cnt += 1
        up = 1
        down = 0
        left = 0
        right = 0
    if s[i] == "D" and up == 0:
        down = 1
    elif s[i] == "D" and up == 1:
        cnt += 1
        up = 0
        down = 1
        left = 0
        right = 0
    if s[i] == "L" and right == 0:
        left = 1
    elif s[i] == "L" and right == 1:
        cnt += 1
        up = 0
        down = 0
        left = 1
        right = 0
    if s[i] == "R" and left == 0:
        right = 1
    elif s[i] == "R" and left == 1:
        cnt += 1
        up = 0
        down = 0
        left = 0
        right = 1
print(cnt + 1)