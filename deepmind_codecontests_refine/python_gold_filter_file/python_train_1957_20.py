N=int(input())
S=input()
ANS=""
for i in range(len(S)):
    ANS+=chr(65+((ord(S[i])+N)-65)%26)
print(ANS)