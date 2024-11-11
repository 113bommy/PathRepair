S = input()

print('Yes' if all(S.count(s) == 2 for s in S) else 'No')
