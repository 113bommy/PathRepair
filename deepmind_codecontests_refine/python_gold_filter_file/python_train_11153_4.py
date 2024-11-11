import random

n = int(input())
input_str = list(input())

color = set(['R', 'G', 'B'])
changes = 0

i = 1
if n != 1:
    while i < n - 1:
        if input_str[i] == input_str[i-1]:
            options = color - set([input_str[i], input_str[i + 1]])
            input_str[i] = random.choice(tuple(options))
            changes += 1
    
        i += 1
    
    if input_str[i] == input_str[i - 1]:
        options = color - set(input_str[i])
        input_str[i] = random.choice(tuple(options))
        changes += 1

print(changes)
print(''.join(input_str))