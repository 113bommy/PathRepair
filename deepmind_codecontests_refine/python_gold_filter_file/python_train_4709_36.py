Word = input()
Comparison = Word.upper()
Comparison2 = (Word[0].lower() + Word[1:].upper())

if Comparison == Word:
    print(Word.lower())
elif Comparison2 == Word:
    print(Word.capitalize())
else:
    print(Word)