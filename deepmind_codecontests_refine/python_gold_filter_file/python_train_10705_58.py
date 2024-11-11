x = input()
print('Yes' if int(x)%sum(map(int,x)) == 0 else 'No')
