x = input()
print('No' if int(x) % sum(map(int,x)) else 'Yes')
