lst = ["a", "i", "e", "o", "y", "u"]
s = input()
for i in range(len(s)-1, -1, -1):
    if (s[i].isalpha()):
        if (s[i].lower() in lst):
            print("YES")
            break
        else:
            print("NO")
            break