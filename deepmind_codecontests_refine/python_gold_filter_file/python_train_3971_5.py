Vowels = 'aeiou'
X1 = input()
X2 = input()
if len(X1) != len(X2):
    print("NO")
    exit()
for i in range(len(X1)):
    if (X1[i] in Vowels and X2[i] not in Vowels) or (X2[i] in Vowels and X1[i] not in Vowels):
        print("NO")
        exit()
print("YES")
