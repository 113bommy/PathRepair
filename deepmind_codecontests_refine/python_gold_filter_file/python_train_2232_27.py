a1, a2, a3, a4 = map(int, input().split())
s = str(input())
calories = 0
for i in range(0, (len(s))):
    if int(s[i]) == 1:
        calories = calories + a1
    elif int(s[i]) == 2:
        calories = calories + a2
    elif int(s[i]) == 3:
        calories = calories + a3
    else:
        calories = calories + a4
print(calories)