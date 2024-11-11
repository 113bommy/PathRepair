s = input()
char_dict = {}
count = 0
for c in s:
    if c not in char_dict.keys():
        char_dict[c] = 1
        count += 1
print("CHAT WITH HER!" if count % 2 == 0 else "IGNORE HIM!")