def check(n):
    if n =='a':
        return True

    if n =='i':
        return True

    if n =='u':
        return True

    if n =='e':
        return True

    if n =='o':
        return True
    return False

s = input()

flag = True
for i in range(len(s)-1):
    if not(check(s[i]) or s[i] =='n') and not(check(s[i+1])):
        print("No")
        flag = False
        break
if flag:
    if not(check(s[-1]) or s[-1] == 'n'):
        print("NO")
    else:
        print("YES")
