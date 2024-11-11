
string = input()
substring = 'QAQ'
res = []
count = 0
for i in range(len(string)):
    if string[i] == 'A':
        count += string[:i].count('Q') * string[i:].count('Q')
print(count)