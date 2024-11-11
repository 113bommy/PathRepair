O=input()
E=input() + ' '
print(''.join([O[i]+E[i] for i in range(len(O))]))