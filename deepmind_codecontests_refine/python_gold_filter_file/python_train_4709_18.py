word = input()
if word == word.upper():
    word = word.lower()
elif word == (word[0].lower() + word[1:].upper()):
    word = word.title()
print(word)