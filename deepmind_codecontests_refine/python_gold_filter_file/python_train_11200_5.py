m = {'I' : 20, 'D' : 12, 'O' : 8, 'C' : 6, 'T' : 4}

n = int(input())
ans = 0
for i in range(n):
    ans += m[input()[0]]
print(ans)