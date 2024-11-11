n = int(input())
for i in range(n):
    word = input()
    first_letter = word[0]
    is_switched = False
    for i in range(1, len(word)):
        letter = word[i]
        if first_letter != letter:
            last_letter = word[len(word)-1]
            is_switched = True
            if i == len(word) - 1:
                new_word = word
            else:
                new_word = word[0:i] + last_letter + word[i+1:len(word) - 1] + letter
            print(new_word)
            break
    if is_switched == False:
        print(-1)

