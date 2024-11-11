import math

first_line = input()
second_line = input()

h1 = int(first_line.split(':')[0])
m1 = int(first_line.split(':')[1])

h2 = int(second_line.split(':')[0])
m2 = int(second_line.split(':')[1])

minutes_1 = (h1 * 60) + m1
minutes_2 = (h2 * 60) + m2

minutes_def = minutes_2 - minutes_1
minutes_def = round(minutes_def / 2)

result_h = h1 + math.floor(minutes_def / 60)
result_m = m1 + minutes_def % 60

if result_m >= 60:
    result_m = result_m % 60
    result_h += 1

if result_h < 10:
    result_h = "0" + str(result_h)

if result_m < 10:
    result_m = "0" + str(result_m)

print(str(result_h) + ":" + str(result_m))
