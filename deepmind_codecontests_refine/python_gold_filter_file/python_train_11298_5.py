n = int(input())
rats, men, captain = [], [], []
children_women = []
for i in range(n):
    x = input()
    if x.count(' rat') != 0:
        rats.append(x[:x.index('rat') - 1])
    elif x.count(' child') != 0:
        children_women.append(x[:x.index('child') - 1])
    elif x.count(' woman') != 0:
        children_women.append(x[:x.index('woman') - 1])
    elif x.count(' man') != 0:
        men.append(x[:x.index('man') - 1])
    elif x.count(' captain') != 0:
        captain.append(x[:x.index('captain') - 1])
print(*(rats + children_women + men + captain), sep='\n')
