n, x = list(map(int, input().split()))
set = list(map(int, input().split()))
score = 0
set.sort()

for i in range(x + 1):
    if i != x and i not in set:
        score += 1

    elif i == x and i in set:
        print(score + 1)
        quit()

    elif i == x and i not in set:
        print(score)
        quit()