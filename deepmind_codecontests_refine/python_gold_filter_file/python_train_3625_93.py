import  re
s = input()
print(s[0] == "A" and s[2:-1:].count("C") ==1 and len(re.findall("[a-z]",s)) == len(s)-2 \
        and "AC" or "WA")
