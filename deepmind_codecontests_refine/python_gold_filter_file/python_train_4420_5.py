#40.443A Anton and letters
l = input()
a = []
for i in l:
    if i in "abcdefghijklmnopqrstuvwxyz" and i not in a:
        a.append(i)
print(len(a))