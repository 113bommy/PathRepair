s=input()
n=len(s)
for i in range(0,n):
    for j in range(i+1,n+1):
        t=s[:i]+s[j:]
        #print(t)
        if 'CODEFORCES'==t:
            print('YES')
            exit()
print('NO')
