a = 'A'+input()+'A'
vowels = ['A','E','I','O','U','Y']
temp = 0
counter = 0
jumps = []
for i in a:
    counter += 1
    if i in vowels:
        jumps.append(counter)
        counter = 0
print(max(jumps))