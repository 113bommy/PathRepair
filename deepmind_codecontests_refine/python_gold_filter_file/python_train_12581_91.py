s = input()

a, b = s.find('A'), s.rfind('Z')
print(b + 1 - a)