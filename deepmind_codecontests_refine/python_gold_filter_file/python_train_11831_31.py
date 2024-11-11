s = input()
cnt = 0
lis = ["a", "e", "i", "o", "u"]
num = ["1", "3", "5", "7", "9"]
for i in s:
    if i in lis: cnt += 1
    if i in num: cnt += 1
print(cnt)