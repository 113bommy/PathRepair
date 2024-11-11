import sys

data = []
for line in sys.stdin:
    content = []
    for x in line.split():
        content.append(int(x))
    data.append(content)

for i in range(data[0][0]):
    case = data[2*i + 2]
    case.sort()
    min = case[1] - case[0]
    for j in range(len(case) - 1):
        if case[j + 1] - case[j] < min:
            min = case[j + 1] - case[j]
    print(min)