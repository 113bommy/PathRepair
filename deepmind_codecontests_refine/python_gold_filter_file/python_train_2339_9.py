MyDict = {"rock": list(), "paper": list(), "scissors": list()}
Answers = list()
for i in range(3):
    INPUT = input()
    if i == 0:
        MyDict[INPUT].append('F')
        Answers.append(INPUT)
    elif i == 1:
        MyDict[INPUT].append('M')
        Answers.append(INPUT)
    else:
        MyDict[INPUT].append('S')
        Answers.append(INPUT)
if Answers.count('paper') == 1 and Answers.count('rock') == 2:
    print(MyDict['paper'][0])
    exit()
elif Answers.count('rock') == 1 and Answers.count('scissors') == 2:
    print(MyDict['rock'][0])
    exit()
elif Answers.count('scissors') == 1 and Answers.count('paper') == 2:
    print(MyDict['scissors'][0])
    exit()
print('?')
