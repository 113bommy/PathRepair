a = input()
print('AC' if a[0] == 'A' and 'C' in a[2:-1] and a[1:].replace('C', '', 1).islower() else 'WA')