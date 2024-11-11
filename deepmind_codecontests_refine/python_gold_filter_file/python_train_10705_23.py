a=input()
print('Yes' if int(a)%sum(map(int,a))==0 else 'No')