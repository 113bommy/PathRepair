s = input()
bad = 0
const = "B C D F G H J K L M P Q R S T V W X Y Z".lower().split()
vow = "a o u i e".split()
for i in range(len(s)):
    if s[i] in const:
        if i == len(s)-1 or s[i + 1] not in vow:
            bad = 1

if bad:
    print('NO')
else:
    print('YES')