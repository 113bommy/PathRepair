string_length = int(input())
string = input()

dictionary = {
    'o': 0,
    'n': 0,
    'e': 0,
    'z': 0,
    'r': 0,
}

for i in string:
    dictionary[i] += 1

answer = ''
for i in range(dictionary['n']):
    answer += '1 '
for i in range(dictionary['z']):
    answer += '0 '

print(answer)
