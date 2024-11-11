n = int(input())
word = input()
vowel = ['a', 'e', 'i' , 'o' , 'u' ,'y']
answer = ''
previous_letter = ''
for letter in word:
    if letter in vowel:
        if not (previous_letter in vowel):
            answer += letter
    else:
        answer += letter
    previous_letter = letter
print(answer)