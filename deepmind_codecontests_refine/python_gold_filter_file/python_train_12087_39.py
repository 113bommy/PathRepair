input()
people_answers = list(map(int, input().split()))
if sum(people_answers) > 0:
    print('HARD')
else:
    print('EAsY')
