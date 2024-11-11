n=int(input())
s=input()
fl=0
for i in range(n-1):
    if s[i]>s[i+1]:
        print('YES')
        print(i+1, i + 2)
        fl=1
        break
if not fl: print('NO')