s = input()
a = input()
print('NYOE S'[any(i in a for i in s)::2])