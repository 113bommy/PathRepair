s='AHIMTUVWXYO'
s1=input()
for j,i in enumerate(s1):
    if not i in s:
        print('NO')
        exit(0)
    if s1[j]!=s1[len(s1)-j-1]:
        print('NO')
        exit(0)
print("YES")