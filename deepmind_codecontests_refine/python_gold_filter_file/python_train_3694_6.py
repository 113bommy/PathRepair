from string import ascii_lowercase

word = str(input())
found = False

def get_palindrome(word, len):
    global found
    for letter in ascii_lowercase:
        new_word = word[:x] + letter + word[x:]
        if (new_word[::-1] == new_word):
            print(new_word)
            found = True
            return

for x in range(len(word) + 1):
    if not found:
        get_palindrome(word, x)
    
if not found:
    print('NA')


