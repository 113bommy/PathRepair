vowel = ["a","i","u","e","o","y"]
word = list(input().lower())
for i in range(6):
    for j in range (len(word)):
        if vowel[i] in word:
            word.remove(vowel[i])
for i in range (len(word)):
    print("."+word[i],end="")