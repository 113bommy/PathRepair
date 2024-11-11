s = input()
z = s.count('0')
print(min(z, len(s)-z)*2)