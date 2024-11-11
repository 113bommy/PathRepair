length = int(input().split(" ")[1])
lanterns = list(int(x) for x in input().split(" "))
lanterns.sort()

maximum = 0
for i in range(1, len(lanterns)):
    diff = lanterns[i] - lanterns[i - 1]
    if diff > maximum:
        maximum = diff

maximum /= 2

if lanterns[0] > maximum:
    maximum = lanterns[0]

if length - lanterns[-1] > maximum:
    maximum = length - lanterns[-1]

print(maximum)
