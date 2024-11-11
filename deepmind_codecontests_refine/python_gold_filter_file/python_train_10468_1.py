alph = "abcdefgh"
s = input()
res = 0

if s[0] == "a" or s[0] == "h":
    res += 1
if s[1] == "1" or s[1] == "8":
    res += 1
if res == 0:
    print("8")
elif res == 1:
    print("5")
elif res == 2:
    print("3")
