S = input()
print(len(S) - S[::-1].index('Z') - S.index('A'))