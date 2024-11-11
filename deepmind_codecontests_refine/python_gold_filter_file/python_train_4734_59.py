s = input()
vowels = "aeiouy"

k = s.replace(" ","").lower()

if k[len(k)-2] in vowels:
    print("YES")
else:
    print("NO")