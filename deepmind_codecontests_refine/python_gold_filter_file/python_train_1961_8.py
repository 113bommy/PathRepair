s = input()
if s[1:].count("9") == len(s)-1:
    print(sum(map(int, s)))
else:
    print(int(s[0])-1 + 9*(len(s)-1))
