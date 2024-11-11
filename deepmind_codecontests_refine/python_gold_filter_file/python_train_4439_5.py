s = list(input())
if "1" in s: 
    s = s[s.index("1"):]
    if s.count("0")>5:
        print("yes")
    else:
        print("no")
else:
    print("no")
#print(bin(64))