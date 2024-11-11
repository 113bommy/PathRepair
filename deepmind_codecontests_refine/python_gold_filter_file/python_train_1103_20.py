t = int(input())
s = input()

numbers = [0]*10
sum = 0

for i in s:
    numbers[int(i)] += 1
    sum += int(i)

if sum >= t:
    print(0)
else:
    ans = 0
    for i in range(0, 10):
        if numbers[i] == 0:
            continue
        for j in range(1, numbers[i]+1):
            if sum + (9 - i) * j >= t:
                sum += (9 - i) * j
                ans += j
                break
        if sum >= t:
            break
        else:
            sum += (9 - i) * numbers[i]
            ans += numbers[i]
    print(ans)