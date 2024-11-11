A = int(input()); ans = """YES
1 * 2 = 2
3 * 4 = 12"""
if A >= 5:
    if A % 2:
        ans = """YES
5 - 3 = 2
2 * 4 = 8
1 + 2 = 3
8 * 3 = 24"""
        for a in range(int(A/2 - 5/2)):
            ans += '\n%d - %d = 1'%(2*a+7, 2*a+6)
            ans += "\n1 * 24 = 24"
    else:
        ans += "\n2 * 12 = 24"  
        for a in range(int(A/2 - 6/2)+1):
            ans += "\n%d - %d = 1"%(2*a+6, 2*a+5)
            ans += "\n1 * 24 = 24"  
elif A <= 3:
    ans = 'NO'
else:
    ans += '\n12 * 2 = 24'
print(ans)
