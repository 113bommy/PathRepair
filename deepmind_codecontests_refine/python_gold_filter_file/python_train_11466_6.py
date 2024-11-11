def counter(bracket):
    left = 0
    right = 0
    stack = []
    for i in bracket:
        if i == "(":
            stack.append(i)
        else:
            if stack:
                stack.pop()
            else:
                right += 1
    left += len(stack)
    return left,right

n = int(input())

match = {}


for _ in range(n):
    now = input()
    count = counter(now)
    if count in match:
        match[count] += 1
    else:
        match[count] = 1

total = 0
for i in match:

    if i[::-1] in match:
        if i == (0,0):
            total += match[i]//2
        if (i[0] == 0 and i[1] != 0) or (i[1] == 0 and i[0] != 0):
            total += min(match[i],match[i[::-1]])
        match[i] = 0
        match[i[::-1]] = 0

print(total)