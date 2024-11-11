s=input()
for i in range(26):
    for j in range(len(s)+1):
        s2=s[:j]+chr(ord('a')+i)+s[j:]
        if s2==s2[::-1]:
            print(s2)
            exit()
print('NA')
