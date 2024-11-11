lens = input().split()
s1 = input()
s2 = input()
min_count = int(lens[0])
min_answer = list()

for start in range(int(lens[1]) - int(lens[0]) + 1):
    diff = 0
    answer = list()

    for i in range(int(lens[0])):
        if (s1[i] != s2[start+i]):
            diff += 1
            answer.append(str(i+1))

    if diff <= min_count:
        min_count = diff
        min_answer = answer

print(min_count)
if min_count > 0:
    print(' '.join(min_answer))
