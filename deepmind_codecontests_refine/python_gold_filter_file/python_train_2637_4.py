n = int(input())
sum1 = 0

list1 = list(map(int, input().split()))
one = list1.count(1)
two = list1.count(2)
three = list1.count(3)
four = list1.count(4)

sum1 += four

sum1 += three
if one >= three:
    one -= three
else:
    one = 0

sum1 += two // 2
if two % 2 != 0:
    sum1 += 1
    one -= 2

if one > 0:
    sum1 += one // 4
    if one % 4 > 0:
        sum1 += 1

print(sum1)
