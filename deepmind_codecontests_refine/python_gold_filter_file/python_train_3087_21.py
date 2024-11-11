vowels = ['a', 'e', 'i', 'o', 'u', 'y']
length = int(input())
word = input()
offset = 0
for i in range(length-1):
    if word[i-offset] in vowels and word[i+1-offset] in vowels:
        word = word[:i+1-offset] + word[i+2-offset:]
        offset +=1
print(word)
