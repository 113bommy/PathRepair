def isRated(scores1,scores2):
    if scores1 != scores2:
        return "rated"
    if sorted(scores1,reverse=True) == list(scores2):
        return "maybe"
    else:
        return "unrated"


nums = input()
scoresList1 = []
scoresList2 = []

for _ in range(int(nums)):
    items = input().split()
    scoresList1.append(int(items[0]))
    scoresList2.append(int(items[1]))


print(isRated(scoresList1,scoresList2))
