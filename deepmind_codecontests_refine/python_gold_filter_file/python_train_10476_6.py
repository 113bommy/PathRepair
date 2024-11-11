s = input()

count = 0

for i in range(len(s)):
    if s[i] == "Q":
        while "A" in s[i+1:]:
            j = i + 1 + s[i + 1:].find("A")
            q = s[j + 1:].count("Q")
            count = count + q
            i = j 
        
print(count)