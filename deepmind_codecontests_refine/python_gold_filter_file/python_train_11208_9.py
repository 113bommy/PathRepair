n = int(input())
input_str = input()
count = 0
for i in range(len(input_str) - 2):
    if input_str[i: i + 3] == 'xxx':
        count += 1

print(count)