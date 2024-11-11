s = list(input())
flag = "Yes"

for x in s:
    if s.count(x) % 2 != 0:
        flag = "No"

print(flag)