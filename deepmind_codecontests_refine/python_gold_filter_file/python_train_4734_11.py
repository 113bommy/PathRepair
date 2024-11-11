A={'a','e','i','o','u','y','A','E','I','O','U','Y'}
a=input()
for i in range(len(a)-1,-1,-1):
    if ord('A')<=ord(a[i])<=ord('Z') or ord('a')<=ord(a[i])<=ord('z'):
        if a[i] in A:
            print('YES')
            break
        else:
            print('NO')
            break