n = input()
n = int(n)
ans = 0
for i in range (n) :
    x = str(input())
 
    if x[1]=='+':
           ans += 1
    elif x[1]=='-':
            ans -= 1

print(ans)
