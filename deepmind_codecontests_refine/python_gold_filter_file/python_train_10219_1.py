from collections import Counter
nums, num_questions = map(int, input().split())
questions = list(map(int, input().split()))
exist = set()
things = dict(Counter(questions))
nums = nums * 3 - 2 - len(things)
for i in questions:
    if i not in exist:
        exist.add(i)
        if things.get(i - 1):
            nums -= 1
        if things.get(i + 1):
            nums -= 1
    things[i] -= 1
print(nums)
