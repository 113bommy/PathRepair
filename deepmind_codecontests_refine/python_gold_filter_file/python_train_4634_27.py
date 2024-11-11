word = input()

hello_word = 'hello'
i = 0
position = 0
positions = [0, 0, 0, 0, 0]

while i < len(hello_word):
    meet_char = 0
    while position < len(word) and meet_char == 0:
        if word[position] == hello_word[i]:
            positions[i] = position
            meet_char = 1
        position += 1
    i += 1

j = 0

#print(positions)
answer = 'YES'
while j < len(positions)-1 and answer == 'YES':
    if positions[j] > positions[j+1] or len(word) < len(hello_word):
        answer = 'NO'
    else:
        answer = 'YES'
    j += 1

print(answer)