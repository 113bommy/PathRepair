mirror_letters = "AITHMOUVWXY"
name = input()

flag = True
for ch in name:
    if not ch in mirror_letters:
        flag = False

for i in range(len(name)):
    if name[i] != name[len(name)-i-1]:
        flag = False

if flag: print("YES")
else: print("NO")
