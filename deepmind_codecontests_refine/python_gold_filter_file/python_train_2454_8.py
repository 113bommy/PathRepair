lemons = int(input())
apples = int(input()) // 2
pears = int(input()) // 4
total_sum = min(lemons, apples, pears) * 7
if apples * 2 < 2 or pears * 4 < 4:
    print(0)
else:
    print(total_sum)
