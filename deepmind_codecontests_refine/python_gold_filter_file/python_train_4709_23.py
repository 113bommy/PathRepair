word = input()
word_list = list(word)
if word.istitle() and 2 <= len(word_list):
    pass
elif word.isupper():
    word = word.lower()
elif word_list[0].islower():
    word_list_mod = word_list
    word_list_mod.remove(word_list_mod[0])
    word_list_mod_check = []
    for i in word_list_mod:
        word_list_mod_check.append(True) if i.isupper() else word_list_mod_check.append(False)
    if False in word_list_mod_check:
        pass
    else:
        word = word.title()
print(word)
