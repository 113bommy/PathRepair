s = input()
for  i in range(26):
    for j  in range(len(s) + 1):
        b = s[:j] + chr(97 + i) + s[j:]
        if(b == b[::-1]):
            print(b)
            exit()
    
print("NA")