S = input()
print('Yes' if int(S)%sum(map(int, S))==0 else 'No')