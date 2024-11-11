a = input()
s1 = 0
for i in a:
    if (i in '13579') or (i in 'aeiou'):
        s1 += 1

print(s1 )