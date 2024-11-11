from sys import stdin

string = stdin.readline()[:-1]
valid = set(["A", "H", "I", "M", "O", "T", "U", "W", "X", "Y", "V"])
size = len(string)
for i in range((size + 1) // 2):
    if (not(string[i] in valid)) or (string[i] != string[size - i - 1]):
        print("NO")
        exit()
print("YES")
