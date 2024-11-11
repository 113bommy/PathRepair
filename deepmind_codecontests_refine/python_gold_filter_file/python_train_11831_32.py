s = input()
answer = 0
for x in s:
    if x == '1' or x == '3' or x == '5' or x == '7' or x == '9' or x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u':
        answer += 1

print(answer)
