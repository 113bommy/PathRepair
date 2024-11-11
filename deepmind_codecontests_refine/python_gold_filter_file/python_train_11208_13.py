len = input()
str = input()
count = 0
res = 0
new_word = ""
for i in str:
    if i == "x":
        count += 1
    else:
        count = 0

    if count == 3:
        res += 1
        count = 2
    else:
        new_word += i

print(res)