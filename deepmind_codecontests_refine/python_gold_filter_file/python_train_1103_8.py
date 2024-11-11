# https://v2.bigocoder.com/courses/41/lectures/557/problems/391?view=statement

k = int(input())
n = input()

_sum = 0
for i in n:
    _sum += int(i)

temp = []
temp.extend(n)
temp.sort()

count = 0
i = 0
while k > _sum:
    if temp[i] != '9':
        _sum += 9 - int(temp[i])
        count += 1
    i += 1
    
print(count)