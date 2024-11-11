S = sorted(list(str(input())))
T = sorted(list(str(input())),reverse=True)

print('YNeos'[S>=T::2])