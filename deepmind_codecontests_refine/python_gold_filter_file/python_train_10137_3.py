n = int(input())
digit = input()
if n == 3:
    lst = [i for i in digit]
else :
    if n % 2 == 0 :
        lst = []
        for i in range(1,n+1):
            if i % 2 == 1 and i != 1 and i != n+1:
                lst.append('-')
            lst.append(digit[i-1])
    else :
        lst = []
        for i in range(n):
            if i == 2 :
                lst.append('-')
            if i > 4 and i % 2 == 1 and i != n:
                lst.append('-')
            lst.append(digit[i])
ans = "".join(lst)
print(ans)
